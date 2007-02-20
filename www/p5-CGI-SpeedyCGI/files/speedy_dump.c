/*
 * Copyright (C) 2007  Jun Kuriyama.  All rights reserved.
 *
 * You can redistribute it and/or modify it under the same terms as
 * CGI::SpeedyCGI itself.
 *
 * $FreeBSD$
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <sys/uio.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "speedy_main.h"
#include "speedy_inc.h"

slotnum_t speedy_slot_check(slotnum_t slotnum) {
  return slotnum;
}

char* ptime(const time_t *t) {
  static char buf[256] ;
  struct tm *tm = localtime(t);
  strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm);
  return buf;
}

int
main(int argc, char **argv)
{
  char filename[PATH_MAX];
  int sz = 0;
  char *data = NULL;

  sprintf(filename, "/tmp/speedy.6.%x.F", geteuid());

  FILE *fh = fopen(filename, "r");
  if (fh) {
    struct stat st;
    if (stat(filename, &st) == 0) {
      sz = st.st_size;
    }

    if (sz) {
      data = malloc(sz);
      fread(data, 1, sz, fh);
    }
  } else {
    printf("Cannot read file (%s).\n", filename);
  }

  if (data) {
    speedy_file_t *speedy_file_maddr = (speedy_file_t*)data;
    file_head_t *h = &FILE_HEAD;
    slotnum_t slotnum, num1;
    slot_t *slot;
    int i;
    time_t ctime = h->create_time.tv_sec;

    printf("{\n");
    printf("  header => {\n");
    printf("    create_time   => { sec => %d, usec => %d, text => '%s' },\n", h->create_time.tv_sec, h->create_time.tv_usec, ptime(&ctime));
    printf("    lock_owner    => %d,\n", h->lock_owner);
    printf("    group_head    => %d,\n", h->group_head);
    printf("    group_tail    => %d,\n", h->group_tail);
    printf("    slot_free     => %d,\n", h->slot_free);
    printf("    slots_alloced => %d,\n", h->slots_alloced);
    printf("    fe_run_head   => %d,\n", h->fe_run_head);
    printf("    fe_run_tail   => %d,\n", h->fe_run_tail);
    printf("    file_removed  => %d\n", h->file_removed);
    printf("  },\n");

    printf("  free_slots => [ ");
    for (slotnum = h->slot_free; !BAD_SLOTNUM(slotnum);
	 slotnum = speedy_slot_next(slotnum)) {
      printf("%d", slotnum);
      if (!BAD_SLOTNUM(speedy_slot_next(slotnum))) printf(", ");
    }
    printf(" ],\n");

    printf("  fe_running => [ ");
    for (slotnum = h->fe_run_head; !BAD_SLOTNUM(slotnum);
	 slotnum = speedy_slot_next(slotnum)) {
      printf("%d\n", slotnum);
      if (!BAD_SLOTNUM(speedy_slot_next(slotnum))) printf(", ");
    }
    printf(" ],\n");

    printf("  group_list => {\n");
    for (slotnum = h->group_head; !BAD_SLOTNUM(slotnum);
	 slotnum = speedy_slot_next(slotnum)) {
      gr_slot_t *gr = &FILE_SLOT(gr_slot, slotnum);
      grnm_slot_t *name = &FILE_SLOT(grnm_slot, gr->name_slot);
      scr_slot_t *scr = &FILE_SLOT(scr_slot, gr->script_head);
      printf("    index       => %d,\n", slotnum);
      printf("    be_starting => %d,\n", gr->be_starting);
      printf("    be_parent   => { pid => %d },\n", gr->be_parent);
      printf("    script_head => %d,\n", gr->script_head);
      printf("    scripts     => [\n");
      for (num1 = gr->script_head; !BAD_SLOTNUM(num1);
	   num1 = speedy_slot_next(num1)) {
	scr = &FILE_SLOT(scr_slot, num1);
	printf("      {\n");
	printf("        index   => %d,\n", num1);
	printf("        dev_num => %d,\n", scr->dev_num);
	printf("        ino_num => %d,\n", scr->ino_num);
	printf("        mtime   => { sec => %d, text => '%s' }\n",
	       scr->mtime, ptime(&scr->mtime));
	printf("      }");
	if (!BAD_SLOTNUM(speedy_slot_next(slotnum))) printf(", ");
      }
      printf("  ],\n");
      printf("    name_slot   => { index => %d, text => '%s' },\n",
	     gr->name_slot, name->name);
      printf("    be_head     => %d,\n", gr->be_head);
      printf("    be_tail     => %d,\n", gr->be_tail);
      printf("    fe_head     => %d,\n", gr->fe_head);
      printf("    fe_tail     => %d,\n", gr->fe_tail);
      printf("    fe_wait_list => [\n");
      for (num1 = gr->fe_head; !BAD_SLOTNUM(num1);
	   num1 = speedy_slot_next(num1)) {
	fe_slot_t *fe = &FILE_SLOT(fe_slot, num1);
	printf("      {\n");
	printf("        index       => %d,\n", num1);
	printf("        pid         => { pid => %d },\n", fe->pid);
	printf("        exit_val    => %d,\n", fe->exit_val);
	printf("        backend     => %d,\n", fe->backend);
	printf("        exit_on_sig => %d,\n", fe->exit_on_sig);
	printf("        sent_sig    => %d,\n", fe->sent_sig);
	printf("      },\n");
      }
      printf("    ],\n");
      printf("    be_list => [\n");
      for (num1 = gr->be_head; !BAD_SLOTNUM(num1);
	   num1 = speedy_slot_next(num1)) {
	be_slot_t *be = &FILE_SLOT(be_slot, num1);
	printf("      {\n");
	printf("        index      => %d,\n", num1);
	printf("        pid        => { pid => %d },\n", be->pid);
	printf("        fe_running => %d,\n", be->fe_running);
	printf("        maturity   => %d\n", be->maturity);
	printf("      },\n");
      }
      printf("    ]\n");
      printf("  }\n");
    }
    printf("}\n");
  }

  return 0;
}

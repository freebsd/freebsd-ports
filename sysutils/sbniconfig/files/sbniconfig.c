/*
 *	Copyright (c) 1997
 *	Granch ltd.
 *
 * Redistribution and use in source forms, with and without modification,
 * are permitted provided that this entire comment appear intact.
 *
 * THIS SOURCE CODE IS PROVIDED ``AS IS'' WITHOUT ANY WARRANTIES OF ANY KIND.
 *
 * sbniconfig.c,v 2.0.0 97/08/06
 */

/*
 * SBNI adapter configuration utility
 *
 * Revision 2.0.0  97/08/06
 * Initial revision
 *
 * Revision 2.0.1 97/08/11
 * Additional internal statistics support (tx statistics)
 * 
 * Revisuion 2.1 Jul 7 2000
 * Added feature to specify baud rate and rxl instead of flags
 * 
 *
 */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/sockio.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "if_sbnivar.h"

char* rate_tab[] = {
	"0",
	"1",
	"2",
	"3"
};

int main(argc, argv)
int argc;
char *argv[];
{
   char *if_name;
   int s;
   struct ifreq ifr;
   struct sbni_in_stats in_stats;
   
   struct sbni_flags flags;
   
   int rxl=-1,baud=-1;
   int rxlfix=1<<6;
   
   
   if(argc < 2 || argc > 4){
      fprintf(stderr, "usage:\tsbniconfig if_name [flags]\n");
      fprintf(stderr, "\tsbniconfig if_name baud rxl\n");
      fprintf(stderr, "e.g.: \tsbniconfig sbni0 0xdeadbeef or \n\tsbniconfig sbni0 2 15\n\tsbniconfig sbni0 0 auto\n");
      
      exit(1);
   }
   if_name = argv[1];
   if(argc == 3 || argc == 4){
      char* endptr;	      
      if(argc == 3){
	 *(u_int32_t*)&flags = strtoul(argv[2], &endptr, 0);
	 if(*endptr){
	    fprintf(stderr,
		    "sbniconfig: invalid flags specified\n");
	    exit(1);
	 }
	 
      }else{
	 baud=atoi(argv[2]);
	 if(strcasecmp(argv[3],"auto")){
	    /* NON auto */
	    rxl=atoi(argv[3]);
	    rxlfix=1<<6;
	 }else{
	    rxl=0;
	    rxlfix=0;
	 }
	 
	 if((baud < 0) || (baud > 3) || (rxl < 0) || (rxl > 15)){
	    printf("incorrect params.\n");
	    exit(1);
	 }
	 
	 printf("baud rate = %d\n",baud);

	 if(!rxlfix)
	   printf("rxl = auto\n");
	 else{
	    printf("rxl = %d\n",rxl);
	 }
	 
	 srandom(time(NULL));
	 
	 *(u_int32_t*)&flags = random();	 
	 *((u_char*) &flags + 3) = rxl | rxlfix | (baud<<4) | (1<<7);
	 printf("new flags = 0x%x\n",flags);
      }
      
      flags.mac_addr = htonl(flags.mac_addr) >> 8;
   }
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   if(s < 0){
      perror("sbniconfig: socket");
      exit (1);
   }
   
   strncpy(ifr.ifr_name, if_name, sizeof (ifr.ifr_name));
   ifr.ifr_addr.sa_family = AF_INET;
   
   if(argc == 2){
      if(ioctl(s, SIOCGHWFLAGS, (caddr_t)&ifr) < 0){
	 perror("sbniconfig: SIOCGHWFLAGS");
	 exit(1);
      }
      flags = *(struct sbni_flags*)&ifr.ifr_data;
      
      ifr.ifr_data = (caddr_t)&in_stats;
      if(ioctl(s, SIOCGINSTATS, (caddr_t)&ifr) < 0){
	 perror("sbniconfig: SIOCGINSTATS");
	 exit(1);
      }
      
      printf("%s:\tMAC addr: 00:ff:01:%02x:%02x:%02x\n"
	     "\treceive level: 0x%x (%s)\n"
	     "\tbaud rate: %s (%s)\n"
	     "\tTotal rx=%u\tBad rx=%u\tGood rx=%u\tTimeouts=%u\n"
	     "\tError frame ratio %6.2f%%\n"
	     "\tTotal tx=%u\tResend tx=%u\tImmediate tx=%u\n",
	     if_name,
	     *(u_char*) &flags,
	     *(((u_char*) &flags)+1),
	     *(((u_char*) &flags)+2),
	     (unsigned) flags.rxl,
	     flags.fixed_rxl ? "fixed" : "autodetected",
	     rate_tab[flags.rate], 
	     flags.fixed_rate ? "fixed" : "autodetected",
	     in_stats.all_rx_number,
	     in_stats.bad_rx_number,
	     in_stats.all_rx_number - in_stats.bad_rx_number,
	     in_stats.timeout_number,
	     (float)(in_stats.bad_rx_number*100./(in_stats.all_rx_number+0.01)),
	     in_stats.all_tx_number,
	     in_stats.resend_tx_number,
	     in_stats.all_tx_number - in_stats.resend_tx_number);
   }
   else if((argc == 3) || (argc ==4 )){      
      if(*(caddr_t*)&flags != 0){
	 ifr.ifr_data = *(caddr_t*)&flags;
	 if(ioctl(s, SIOCSHWFLAGS, (caddr_t)&ifr) < 0){
	    perror("sbniconfig: SIOCSHWFLAGS");
	    exit(1);
	 }
      }
      if(ioctl(s, SIOCRINSTATS, (caddr_t)&ifr) < 0){
	 perror("sbniconfig: SIOCRINSTATS");
	 exit(1);
      }
   }
   
   close (s);
   return 0;
}

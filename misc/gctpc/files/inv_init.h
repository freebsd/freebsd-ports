#ifndef INCLUDED_INV_INIT_H
#define INCLUDED_INV_INIT_H

void
inv_init(long int insys, long int inzone, double *inparm, long int indatum,
         char *fn27, char *fn83, long int *iflg, InverseTransFunc inv_trans[]);

#endif    /* INCLUDED_INV_INIT_H */

*** /tmp/T0fSaqTh	Sun Nov  2 07:48:14 2008
--- proc.c	Sun Nov  2 07:44:24 2008
***************
*** 841,847 ****
  {
  	if (Lf->sf & SELEXCLF)
  	    return;
! 	if (((Selflags & SELNET) == SELNET) && !(Lf->sf & SELNET))
  	    return;
  	Lp->pss |= PS_SEC;
  	if (Plf)
--- 841,847 ----
  {
  	if (Lf->sf & SELEXCLF)
  	    return;
! 	if ((Selflags == SELNET) && !(Lf->sf & SELNET))
  	    return;
  	Lp->pss |= PS_SEC;
  	if (Plf)

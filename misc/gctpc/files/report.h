#ifndef INCLUDED_REPORT_H
#define INCLUDED_REPORT_H

// Functions declartions for report.cc.
// Was not provided in the original gctpc distribution.

int
init(long int ipr, long int jpr, char *efile, char *pfile);

void
close_file(void);

void
ptitle(char *A);

void 
radius(double A);

void
radius2(double A, double B);

void
cenlon(double A);

void
cenlonmer(double A);

void
cenlat(double A);

void
origin(double A);

void
stanparl(double A, double B);

void
stparl1(double A);

void
offsetp(double A, double B);

void
genrpt(double A, char *S);

void
genrpt_long(long int A, char *S);

void
pblank(void);

void
p_error(char *what, char *where);

#endif  // INCLUDED_REPORT_H

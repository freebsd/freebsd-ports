#ifndef GCTPC_H
#define GCTPC_H

#include "proj.h"

/* This didn't come with the original gctpc distribution. 
   But it *should* have. -- jamie 2/14/95 */

void gctp(double* incoor, 
          long*   insys, 
          long*   inzone,
          double* inparm,
          long*   inunit,
          long*   indatum,
          long*   ipr,
          char*   efile,
          long*   jpr,
          char*   pfile,
          double* outcoor,
          long*   outsys,
          long*   outzone,
          double* outparm,
          long*   outunit,
          long*   outdatum,
          char*   fn27,
          char*   fn83,
          long*   iflg);

long
alberforint(double r_maj, double r_min, double lat1, double lat2, double lon0, 
            double lat0, double false_east, double false_north);

long
alberfor(double lon, double lat, double *x, double *y);

long
alberinvint(double r_maj, double r_min, double lat1, double lat2, double lon0, 
            double lat0, double false_east, double false_north);

long
alberinvint(double r_maj, double r_min, double lat1, double lat2, double lon0,
            double lat0, double false_east, double false_north);

long
alberinvint(double r_maj, double r_min, double lat1, double lat2, double lon0,
            double lat0, double false_east, double false_north);

long
alberinv(double x, double y, double *lon, double *lat);

long
alconforint(double r_maj, double r_min, double false_east, double false_north);

long
alconfor(double lon, double lat, double *x, double *y);

long
alconinvint(double r_maj, double r_min, double false_east, double false_north);

long
alconinv(double x, double y, double *lon, double *lat);

long
azimforint(double r_maj, double center_lon, double center_lat, double false_east,
           double false_north);

long
azimfor(double lon, double lat, double *x, double *y);

long
aziminvint(double r_maj, double center_lon, double center_lat, double false_east,
           double false_north);

long
aziminv(double x, double y, double *lon, double *lat);

long
eqconforint(double r_maj, double r_min, double lat1, double lat2, 
            double center_lon, double center_lat, double false_east,
            double false_north, long int mode);

long
eqconfor(double lon, double lat, double *x, double *y);

long
eqconinvint(double r_maj, double r_min, double lat1, double lat2, 
            double center_lon, double center_lat, double false_east,
            double false_north, long int mode);

long
eqconinv(double x, double y, double *lon, double *lat);

long
equiforint(double r_maj, double center_lon, double lat1, double false_east, 
           double false_north);

long
equifor(double lon, double lat, double *x, double *y);

long
equiinvint(double r_maj, double center_lon, double lat1, 
           double false_east, double false_north);

long
equiinv(double x, double y, double *lon, double *lat);

long
gnomforint(double r, double center_long, double center_lat, 
           double false_east, double false_north);

long
gnomfor(double lon, double lat, double *x, double *y);

long
gnominvint(double r, double center_long, double center_lat, double false_east, 
           double false_north);

long
gnominv(double x, double y, double *lon, double *lat);

long
goodforint(double r);

long
goodfor(double lon, double lat, double *x, double *y);

long
goodinvint(double r);

long
goodinv(double x, double y, double *lon, double *lat);

long
gvnspforint(double r, double h, double center_long, double center_lat,
            double false_east, double false_north);

long
gvnspfor(double lon, double lat, double *x, double *y);

long
gvnspinvint(double r, double h, double center_long, double center_lat, 
            double false_east, double false_north);

long
gvnspinv(double x, double y, double *lon, double *lat);

long
hamforint(double r, double center_long, double false_east, double false_north);

long
hamfor(double lon, double lat, double *x, double *y);

long
haminvint(double r, double center_long, double false_east, double false_north);

long
haminv(double x, double y, double *lon, double *lat);

long
imolwforint(double r);

long
imolwfor(double lon, double lat, double *x, double *y);

long
imolwinvint(double r);

long
imolwinv(double x, double y, double *lon, double *lat);

long
lamazforint(double r, double center_long, double center_lat, double false_east, 
            double false_north);

long
lamazfor(double lon, double lat, double *x, double *y);

long
lamazinvint(double r, double center_long, double center_lat, double false_east, 
            double false_north);

long
lamazinv(double x, double y, double *lon, double *lat);

long
lamccforint(double r_maj, double r_min, double lat1, double lat2, double c_lon, 
            double c_lat, double false_east, double false_north);

long
lamccfor(double lon, double lat, double *x, double *y);

long
lamccinvint(double r_maj, double r_min, double lat1, double lat2, double c_lon, 
            double c_lat, double false_east, double false_north);

long
lamccinv(double x, double y, double *lon, double *lat);

long
merforint(double r_maj, double r_min, double center_lon, double center_lat, 
          double false_east, double false_north);

long
merfor(double lon, double lat, double *x, double *y);

long
merinvint(double r_maj, double r_min, double center_lon, double center_lat, 
          double false_east, double false_north);

long
merinv(double x, double y, double *lon, double *lat);

long
millforint(double r, double center_long, double false_east, double false_north);

long
millfor(double lon, double lat, double *x, double *y);

long
millinvint(double r, double center_long, double false_east, double false_north);

long
millinv(double x, double y, double *lon, double *lat);

long
molwforint(double r, double center_long, double false_east, double false_north);

long
molwfor(double lon, double lat, double *x, double *y);

long
molwinvint(double r, double center_long, double false_east, double false_north);

long
molwinv(double x, double y, double *lon, double *lat);

long
obleqforint(double r, double center_long, double center_lat, double shape_m, 
            double shape_n, double angle, double false_east, double false_north);

long
obleqfor(double lon, double lat, double *x, double *y);

long
obleqinvint(double r, double center_long, double center_lat, double shape_m, 
            double shape_n, double angle, double false_east, double false_north);

long
obleqinv(double x, double y, double *lon, double *lat);

long
omerforint(double r_maj, double r_min, double scale_fact, double azimuth,
           double lon_orig, double lat_orig, double false_east,
           double false_north, double lon1, double lat1, double lon2,
           double lat2, long int mode);

long
omerfor(double lon, double lat, double *x, double *y);

long
omerinvint(double r_maj, double r_min, double scale_fact, double azimuth,
           double lon_orig, double lat_orig, double false_east,
           double false_north, double lon1, double lat1, double lon2,
           double lat2, long int mode);

long
omerinv(double x, double y, double *lon, double *lat);

long
orthforint(double r_maj, double center_lon, double center_lat, double false_east,
           double false_north);

long
orthfor(double lon, double lat, double *x, double *y);

long
orthinvint(double r_maj, double center_lon, double center_lat, 
           double false_east, double false_north);

long
orthinv(double x, double y, double *lon, double *lat);

long
polyforint(double r_maj, double r_min, double center_lon, double center_lat, 
           double false_east, double false_north);

long
polyfor(double lon, double lat, double *x, double *y);

long
polyinvint(double r_maj, double r_min, double center_lon, double center_lat, 
           double false_east, double false_north);

long
polyinv(double x, double y, double *lon, double *lat);

long
psforint(double r_maj, double r_min, double c_lon, double c_lat, 
         double false_east, double false_north);

long
psfor(double lon, double lat, double *x, double *y);

long
psinvint(double r_maj, double r_min, double c_lon, double c_lat, double false_east,
         double false_north);

long
psinv(double x, double y, double *lon, double *lat);

long
robforint(double r, double center_long, double false_east, double false_north);

long
robfor(double lon, double lat, double *x, double *y);

long
robinvint(double r, double center_long, double false_east, double false_north);

long
robinv(double x, double y, double *lon, double *lat);

long
sinforint(double r, double center_long, double false_east, double false_north);

long
sinfor(double lon, double lat, double *x, double *y);

long
sininvint(double r, double center_long, double false_east, double false_north);

long
sininv(double x, double y, double *lon, double *lat);

long
somforint(double r_major, double r_minor, long int satnum, long int path, 
          double alf_in, double lon, double false_east, double false_north,
          double time, long int start1, long int flag);

long
somfor(double lon, double lat, double *y, double *x);

long
sominvint(double r_major, double r_minor, long int satnum, long int path, 
          double alf_in, double lon, double false_east, double false_north,
          double time, long int start1, long int flag);

long
sominv(double y, double x, double *lon, double *lat);

long
sterforint(double r_maj, double center_lon, double center_lat, 
           double false_east, double false_north);

long
sterfor(double lon, double lat, double *x, double *y);

long
sterinvint(double r_maj, double center_lon, double center_lat, 
           double false_east, double false_north);

long
sterinv(double x, double y, double *lon, double *lat);

long
stplnforint(long int zone, long int sphere, char *fn27, char *fn83);

long
stplnfor(double lon, double lat, double *x, double *y);

long
stplninvint(long int zone, long int sphere, char *fn27, char *fn83);

long
stplninv(double x, double y, double *lon, double *lat);

long
utmforint(double r_maj, double r_min, double scale_fact, long int zone);

long
utmfor(double lon, double lat, double *x, double *y);

long
tmforint(double r_maj, double r_min, double scale_fact, double center_lon, 
         double center_lat, double false_east, double false_north);

long
tmfor(double lon, double lat, double *x, double *y);

long
utminvint(double r_maj, double r_min, double scale_fact, long int zone);

long
utminv(double x, double y, double *lon, double *lat);

long
tminvint(double r_maj, double r_min, double scale_fact, double center_lon, 
         double center_lat, double false_east, double false_north);

long
tminv(double x, double y, double *lon, double *lat);

long
vandgforint(double r, double center_long, double false_east, double false_north);

long
vandgfor(double lon, double lat, double *x, double *y);

long
vandginvint(double r, double center_long, double false_east, double false_north);

long
vandginv(double x, double y, double *lon, double *lat);

long
wivforint(double r, double center_long, double false_east, double false_north);

long
wivfor(double lon, double lat, double *x, double *y);

long
wivinvint(double r, double center_long, double false_east, double false_north);

long
wivinv(double x, double y, double *lon, double *lat);

long
wviiforint(double r, double center_long, double false_east, double false_north);

long
wviifor(double lon, double lat, double *x, double *y);

long
wviiinvint(double r, double center_long, double false_east, double false_north);

long
wviiinv(double x, double y, double *lon, double *lat);


#endif  /* GCTPC_H */

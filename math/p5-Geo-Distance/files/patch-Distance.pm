--- ../../../Geo-Distance-0.06/Distance.pm	Wed Jun 30 02:12:10 2004
+++ Distance.pm	Sun Jul 11 21:46:44 2004
@@ -1,21 +1,20 @@
 package Geo::Distance;
 
-use 5.006;
 use strict;
-use warnings;
 use Carp;
 use Math::Trig qw( great_circle_distance deg2rad );
 
 require Exporter;
-our @ISA = qw(Exporter);
-our %EXPORT_TAGS = ( 'all' => [ qw(
+use vars qw(@ISA %EXPORT_TAGS @EXPORT_OK $VERSION);
+@ISA = qw(Exporter);
+%EXPORT_TAGS = ( 'all' => [ qw(
 	&distance
 	&distance_calc
 	&find_closest
 	&reg_unit
 	&formula
 ) ] );
-our @EXPORT_OK = (
+@EXPORT_OK = (
 	@{ $EXPORT_TAGS{'all'} },
 	'&distance',
 	'&distance_calc',
@@ -23,11 +22,11 @@
 	'&reg_unit',
 	'&formula'
 );
-our $VERSION = '0.06';
+$VERSION = '0.06';
 
 
 # See Math::Trig for what $rho is.
-our(%rho,$formula);
+use vars qw(%rho $formula);
 $rho{kilometer} = 6378; # Derived from the Math::Trig POD on the 'great_circle_distance'.
 $rho{meter} = $rho{kilometer}*1000; # 1000 meters in one kilometer.
 $rho{centimeter} = $rho{meter}*100; # 100 centimeters in one meter.
@@ -41,7 +40,7 @@
 # Number of units in a single degree (lat or lon) at the equator.
 # Derived from doing dirty_distance('kilometer',10,0,11,0) = 111.317099692185
 # Then dividing that by $unit{kilometer} = 6378
-our $deg_ratio = 0.01745329252;
+use vars qw($deg_ratio); $deg_ratio = 0.01745329252;
 
 
 # New Object Constructor

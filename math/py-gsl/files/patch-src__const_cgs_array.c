--- ./src/const_cgs_array.c.orig	2005-04-27 11:53:37.000000000 +0400
+++ ./src/const_cgs_array.c	2009-11-28 23:12:12.000000000 +0300
@@ -14,10 +14,6 @@
 {"mass_neutron",GSL_CONST_CGS_MASS_NEUTRON,"g"},
 {"rydberg",GSL_CONST_CGS_RYDBERG,"g cm^2 / s^2"},
 {"boltzmann",GSL_CONST_CGS_BOLTZMANN,"g cm^2 / K s^2"},
-{"bohr_magneton",GSL_CONST_CGS_BOHR_MAGNETON,"A cm^2"},
-{"nuclear_magneton",GSL_CONST_CGS_NUCLEAR_MAGNETON,"A cm^2"},
-{"electron_magnetic_moment",GSL_CONST_CGS_ELECTRON_MAGNETIC_MOMENT,"A cm^2"},
-{"proton_magnetic_moment",GSL_CONST_CGS_PROTON_MAGNETIC_MOMENT,"A cm^2"},
 {"molar_gas",GSL_CONST_CGS_MOLAR_GAS,"g cm^2 / K mol s^2"},
 {"standard_gas_volume",GSL_CONST_CGS_STANDARD_GAS_VOLUME,"cm^3 / mol"},
 {"minute",GSL_CONST_CGS_MINUTE,"s"},
@@ -76,9 +72,6 @@
 {"psi",GSL_CONST_CGS_PSI,"g / cm s^2"},
 {"poise",GSL_CONST_CGS_POISE,"g / cm s"},
 {"stokes",GSL_CONST_CGS_STOKES,"cm^2 / s"},
-{"faraday",GSL_CONST_CGS_FARADAY,"A s / mol"},
-{"electron_charge",GSL_CONST_CGS_ELECTRON_CHARGE,"A s"},
-{"gauss",GSL_CONST_CGS_GAUSS,"g / A s^2"},
 {"stilb",GSL_CONST_CGS_STILB,"cd / cm^2"},
 {"lumen",GSL_CONST_CGS_LUMEN,"cd sr"},
 {"lux",GSL_CONST_CGS_LUX,"cd sr / cm^2"},

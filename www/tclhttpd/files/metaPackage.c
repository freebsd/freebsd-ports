#include <tcl.h>

Tcl_PackageInitProc Crypt_Init, Limit_Init, Setuid_Init, Utime_Init;
Tcl_PackageInitProc Httpdate_Init;

int
Tclhttpdbin_Init(Tcl_Interp *I) {

	Crypt_Init(I);
	Limit_Init(I);
	Setuid_Init(I);
	Httpdate_Init(I);

	return TCL_OK;
}

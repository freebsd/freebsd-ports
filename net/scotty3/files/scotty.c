/* All that's needed for bin/scotty, really...	-mi */

#include "tnmInt.h"

static int
Tcl_AppInit(interp)
	Tcl_Interp *interp;
{
	if (Tcl_Init(interp) != TCL_OK) {
		return TCL_ERROR;
	}

	if (Tcl_PkgRequire(interp, "Tnm", TNM_VERSION, 1) == NULL) {
		return TCL_ERROR;
	}

	Tcl_SetVar(interp, "tcl_rcFileName", "~/.tclshrc", TCL_GLOBAL_ONLY);
	return TCL_OK;
}

int
main(argc, argv)
	int argc;
	char **argv;
{
	Tcl_Main(argc, argv, Tcl_AppInit);
}

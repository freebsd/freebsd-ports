DISTNAME	=	xc
PKGNAME		= 	XFree86-3.1

# uncomment one of the 2 lines below!
#X11_ON_CDROM	=	yes
#X11_VIA_FTP		=	yes

#define this if you are short of space - save ~28 Mbytes
#REMOVE_NOT_ESSENTIAL	=	yes


.if defined(X11_ON_CDROM) || defined(X11_VIA_FTP)
build:
.if defined(REMOVE_NOT_ESSENTIAL)
	@rm -rf ${WRKSRC}/test ${WRKSRC}/doc/hardcopy ${WRKSRC}/doc/specs
	@find ${WRKSRC}/ -name '*.orig' -exec rm -f {} ';'
.endif
	@(cd ${WRKSRC}; echo Good night...; make World)
	@touch ${WRKDIR}/.build_done

install:
	@(cd ${WRKSRC}; make install; make install.man)
	@touch ${WRKDIR}/.install_done
.endif


.if defined(X11_ON_CDROM)
.include "Makefile.cdrom"
.elif defined(X11_VIA_FTP)
.include "Makefile.ftp"
.else
all:
	@echo -n
fetch:
	@echo -n
extract:
	@echo -n
configure:
	@echo -n
build:
	@echo -n
install:
	@echo -n
.endif



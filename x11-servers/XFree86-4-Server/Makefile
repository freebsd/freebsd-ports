# New ports collection makefile for:    XFree86
# Version required:     3.1.2
# Date created:         5 January 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.15 1995/10/06 22:11:25 asami Exp $
#

#######################################################################
#                                                                     #
#                        Configurable Section                         #
#                                                                     #
#######################################################################
#
# uncomment one of the 2 lines below!
#(X-Consortium CDROM, O'Reilly 'X-Companion' CDROM, or X by FTP (_*BIG*_)
#X11_ON_CDROM	=	yes
#X11_VIA_FTP	=	yes

#if you are compiling from a cdrom, set the directory where the
# the patch files are
X11FIXES = ${DISTDIR}/xc

#define this if you are short of space - save ~28 Mbytes
#REMOVE_NOT_ESSENTIAL	=	yes

# Define FORCE_PACKAGE from the command line if you want to override
# this and build a package
NO_PACKAGE	=	yes
#######################################################################
DISTNAME	=	xc
PKGNAME		= 	XFree86-3.1.2
CATEGORIES      =	x11
IS_INTERACTIVE=		yes

MAINTAINER=		jmz@FreeBSD.ORG

.if defined(X11_ON_CDROM) || defined(X11_VIA_FTP)

DISTFILES=		# to prevent checksum
do-build:
.if defined(REMOVE_NOT_ESSENTIAL)
	@rm -rf ${WRKSRC}/test ${WRKSRC}/doc/hardcopy ${WRKSRC}/doc/specs
	@find ${WRKSRC}/ -name '*.orig' -exec rm -f {} ';'
.endif
	@(cd ${WRKSRC}; echo Good night...; make World)
	@touch ${WRKDIR}/.build_done

do-install:
	@(cd ${WRKSRC}; make install; make install.man)
	@touch ${WRKDIR}/.install_done
.if defined(X11_ON_CDROM) 
	@find /usr/X11R6/ -name 00_TRANS.TBL -exec rm -f {} ';'
.endif
.endif

.if defined(X11_ON_CDROM)
.if !defined (X11FIXES)
do-configure:
	@echo Edit the makefile and set X11FIXES !!!!
	@exit 1;
.endif
do-fetch:
	@echo -n
do-extract:
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	@echo ${X11FIXES} > ${WRKDIR}/.cdrom
	@${TOUCH} ${TOUCH_FLAGS} ${EXTRACT_COOKIE}

.elif defined(X11_VIA_FTP)
.include "Makefile.ftp"
.else
do-fetch:
	@echo Please set one of the 2 variables X11_ON_CDROM or X11_VIA_FTP 
	@echo before building ${PKGNAME}
	@false
do-extract:
	@echo -n
do-configure:
	@echo -n
do-build:
	@echo Please set one of the 2 variables X11_ON_X_CDROM or X11_VIA_FTP 
	@echo before building ${PKGNAME}
	@false
do-install:
	@echo -n
.endif

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>


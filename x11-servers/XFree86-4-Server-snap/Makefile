# New ports collection makefile for:    XFree86
# Version required:     3.1.2
# Date created:         5 January 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.17 1996/02/15 00:53:15 jmz Exp $
#

#######################################################################
#                                                                     #
#                        Configurable Section                         #
#                                                                     #
#######################################################################
#
# uncomment one of the 2 lines below!
#
# X11_ON_CDROM means you have either X-Consortium CDROM or O'Reilly's
# 'X-Companion' CDROM, X11_VIA_FTP means you have the FreeBSD CDROM
# or want to ftp the whole thing _*BIG*_)
#
#X11_ON_CDROM	=	yes
#X11_VIA_FTP	=	yes

#if you are compiling from a cdrom, set the directory where the
# the patch files are
X11FIXES = ${DISTDIR}

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

DIST_SUBDIR	=	xc

.if defined(DISTDIR)
.if exists (${DISTDIR}/xc-1.tar.gz)
X11_VIA_FTP = yes
.endif
.elif defined(PORTSDIR)
.if exists (${PORTSDIR}/distfiles/xc/xc-1.tar.gz)
X11_VIA_FTP = yes
.endif
.else
.if exists (/usr/ports/distfiles/xc/xc-1.tar.gz)
X11_VIA_FTP = yes
.endif
.endif

.if defined(X11_ON_CDROM) || defined(X11_VIA_FTP)

DISTFILES=		# to prevent checksum
do-build:
.if defined(REMOVE_NOT_ESSENTIAL)
	@rm -rf ${WRKSRC}/test ${WRKSRC}/doc/hardcopy ${WRKSRC}/doc/specs
	@find ${WRKSRC}/ -name '*.orig' -exec rm -f {} ';'
.endif
	@(cd ${WRKSRC}; echo Good night...; make World)

do-install:
	@(cd ${WRKSRC}; make install; make install.man)
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

.elif defined(X11_VIA_FTP)
DISTFILES1	=	xc-1.tar.gz xc-2.tar.gz xc-3.tar.gz
DISTFILES2	=	fix-12 \
			XFree86-3.1.2.diff.gz \
			3.1.2-3.1.2-S.diff.gz
DISTFILES	=	${DISTFILES1} ${DISTFILES2}
MASTER_SITES	=	\
	ftp://ftp.x.org/pub/R6/ \
	ftp://ftp.EU.net/X11/R6/ \
	ftp://ftp.x.org/pub/R6/fixes/ \
	ftp://ftp.EU.net/X11/R6/fixes/ \
	ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.1.2/patches/	\
	ftp://ftp.xfree86.org/pub/XFree86/3.1.2/patches/
EXTRACT_ONLY	=	${DISTFILES1}

pre-patch:
	@echo ${DISTDIR} > ${WRKDIR}/.ftp
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

# New ports collection makefile for:	tcl8.0
# Version required:	8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.7 1998/07/27 21:14:46 hoek Exp $
#

DISTNAME=	tcl8.0p2
PKGNAME=	tcl-8.0.2
CATEGORIES=	lang tcl80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=	jkh@freebsd.org

WRKSRC=		${WRKDIR}/tcl8.0/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

SHLIB_MAJOR=	1
SHLIB_MINOR=	2
MAKEFILE=	makefile
TCL_LIB=	libtcl80.so

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

post-install:
	${LN} -sf ${TCL_LIB_FILE} ${PREFIX}/lib/${TCL_LIB}
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGDIR}/INSTALL.tclsh)
	${SH} ${PKGDIR}/INSTALL.tclsh
.endif

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>

PKG_ARGS+=	-i ${PKGDIR}/INSTALL.tclsh

.if ${PORTOBJFORMAT} == "elf"
TCL_LIB_FILE=	${TCL_LIB}.${SHLIB_MAJOR}
.else
TCL_LIB_FILE=	${TCL_LIB}.${SHLIB_MAJOR}.${SHLIB_MINOR}
.endif

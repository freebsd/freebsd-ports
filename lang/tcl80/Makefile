# New ports collection makefile for:	tcl8.0
# Version required:	8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.9 1998/11/14 09:43:19 asami Exp $
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
PKGINSTALL=	${PKGDIR}/INSTALL.tclsh

SHLIB_MAJOR=	1
SHLIB_MINOR=	2
MAKEFILE=	makefile
TCL_LIB=	libtcl80.so

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
TCL_LIB_FILE=	${TCL_LIB}.${SHLIB_MAJOR}
.else
TCL_LIB_FILE=	${TCL_LIB}.${SHLIB_MAJOR}.${SHLIB_MINOR}
.endif

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

post-install:
	${LN} -sf ${TCL_LIB_FILE} ${PREFIX}/lib/${TCL_LIB}
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>

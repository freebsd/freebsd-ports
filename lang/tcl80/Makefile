# New ports collection makefile for:	tcl8.0
# Version required:	8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.6 1998/07/03 23:06:48 steve Exp $
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

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGDIR}/INSTALL.tclsh)
	${SH} ${PKGDIR}/INSTALL.tclsh
.endif

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>

PKG_ARGS+=	-i ${PKGDIR}/INSTALL.tclsh

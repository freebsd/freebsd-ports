# New ports collection makefile for:	tcl8.1
# Version required:	8.1.a2
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.9 1998/07/04 17:29:15 jdp Exp $
#

DISTNAME=	tcl8.1a2
PKGNAME=	tcl-8.1.a2
CATEGORIES=	lang tcl81
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_1/

MAINTAINER=	jseger@FreeBSD.ORG

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PORTSDIR}/lang/tcl80/pkg/INSTALL.tclsh)
	${SH} ${PORTSDIR}/lang/tcl80/pkg/INSTALL.tclsh
.endif

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>

PKG_ARGS+=      -i ${PORTSDIR}/lang/tcl80/pkg/INSTALL.tclsh

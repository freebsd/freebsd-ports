# New ports collection makefile for:	saferpay
# Date created:		06 September 2001
# Whom:			mb@imp.ch
#
# $FreeBSD$
#

PORTNAME=	saferpay
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.saferpay.com/download/
DISTFILES=	${PORTNAME}_${PORTVERSION}_linux-g++_src.tar.gz

MAINTAINER=	mbr@FreeBSD.org

MAKEFILE=	${WRKSRC}/saferpay/Makefile

USE_GMAKE=	yes
USE_OPENSSL=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}

.if !defined(WITH_P5_API)
pre-build:
	@${ECHO} "-----------------------------------------------------"
	@${ECHO} You are building now the saferpay command line tool.
	@${ECHO} If you like to install the perl API too, break this
	@${ECHO} installation and start it again with WITH_P5_API=YES.
	@${ECHO} "-----------------------------------------------------"
.else
pre-build:
PLIST=		${PKGDIR}/pkg-plist.p5
post-build:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} xs)
post-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} installxs)
.endif

.include <bsd.port.mk>

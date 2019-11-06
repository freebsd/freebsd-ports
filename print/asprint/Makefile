# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	asprint
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	AFTERSTEP/apps/asprint
DISTNAME=	asprint

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple browser to allow a user to print

PLIST_FILES=	bin/asprint
USES=		xorg
USE_XORG=	xmu xpm xt xaw x11
ALL_TARGET=	asprint
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asprint ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

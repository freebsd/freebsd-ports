# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	nbosd
PORTVERSION=	0.5.0
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Displays battery life and CPU frequency with an OSD

LIB_DEPENDS=	libxosd.so:${PORTSDIR}/misc/xosd

PLIST_FILES=	bin/nbosd
PORTDOCS=	README CHANGELOG

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbosd ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

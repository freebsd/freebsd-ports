# New ports collection makefile for:	linux-mplayerplug-in
# Date Created:		17 June 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayerplug-in
PORTVERSION=	3.25
DISTVERSIONSUFFIX=	-fc4
CATEGORIES=	www multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	linux-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Embed MPlayer into browser

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

NO_BUILD=	yes
USE_LINUX_RPM=	yes
LINUX_DIST=	fedora
LINUX_DIST_VER=	4
PREFIX?=	${LOCALBASE}

USE_NPAPI=	linux-*
NPAPI_FILES=	${PLUGINS_EXT:S/^/${PORTNAME}/}
PLUGINS_EXT=	.so .xpt -gmp.so -gmp.xpt -qt.so -qt.xpt -rm.so -rm.xpt -wmp.so -wmp.xpt

post-extract:
	${MKDIR} ${WRKSRC} && ${MV} ${WRKDIR}/usr/lib/mozilla/plugins/* ${WRKSRC}/

.include "${.CURDIR}/Makefile.npapi"
.include <bsd.port.mk>

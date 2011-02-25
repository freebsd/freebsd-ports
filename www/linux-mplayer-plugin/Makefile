# New ports collection makefile for:	linux-mplayerplug-in
# Date Created:		17 June 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayerplug-in
PORTVERSION=	3.55
PORTREVISION=	3
DISTVERSIONSUFFIX=	-1.rh9.rf
CATEGORIES=	www multimedia
MASTER_SITES=	CENKES http://apt.sw.be/packages/mplayerplug-in/ \
		ftp://fr2.rpmfind.net/linux/dag/redhat/9/en/i386/dag/RPMS/
PKGNAMEPREFIX=	linux-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embed MPlayer into browser

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

NO_BUILD=	yes
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	atk gtk2 pango xorglibs
PREFIX?=	${LOCALBASE}
SRC_DISTFILES=
DIST_SUBDIR=   rpm

USE_NPAPI=	linux
NPAPI_WRKSRC=	${WRKDIR}/usr/lib/mozilla/plugins
NPAPI_FILES=	${PLUGINS_EXT:S/^/${PORTNAME}/}
PLUGINS_EXT=	.so .xpt -dvx.so -dvx.xpt -qt.so -qt.xpt -rm.so -rm.xpt -wmp.so -wmp.xpt

.include "${.CURDIR}/Makefile.npapi"
.include <bsd.port.mk>

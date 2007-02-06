# New ports collection makefile for:	linux-mplayerplug-in
# Date Created:		17 June 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayerplug-in
PORTVERSION=	3.35
DISTVERSIONSUFFIX=	-1.rh9.rf
CATEGORIES=	www multimedia
MASTER_SITES=	ftp://fr2.rpmfind.net/linux/dag/redhat/9/en/i386/dag/RPMS/ \
		http://apt.sw.be/packages/mplayerplug-in/
PKGNAMEPREFIX=	linux-
SRC_DISTFILES=

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Embed MPlayer into browser

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
		${LINUXBASE}/usr/lib/libpangoxft-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango\
		${LINUXBASE}/usr/lib/libgobject-2.0.so.0:${PORTSDIR}/devel/linux-glib2

NO_BUILD=	yes
USE_LINUX_RPM=	yes
USE_XLIB=	yes
LINUX_DIST=	fedora
LINUX_DIST_VER=	4
PREFIX?=	${LOCALBASE}

USE_NPAPI=	linux
NPAPI_WRKSRC=	${WRKDIR}/usr/lib/mozilla/plugins
NPAPI_FILES=	${PLUGINS_EXT:S/^/${PORTNAME}/}
PLUGINS_EXT=	.so .xpt -dvx.so -dvx.xpt -qt.so -qt.xpt -rm.so -rm.xpt -wmp.so -wmp.xpt

.include "${.CURDIR}/Makefile.npapi"
.include <bsd.port.mk>

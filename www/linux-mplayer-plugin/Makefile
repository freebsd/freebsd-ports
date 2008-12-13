# New ports collection makefile for:	linux-mplayerplug-in
# Date Created:		17 June 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayerplug-in
PORTVERSION=	3.50
DISTVERSIONSUFFIX=	-1.rh9.rf
PORTREVISION=	2
CATEGORIES=	www multimedia
MASTER_SITES=	CENKES http://apt.sw.be/packages/mplayerplug-in/ \
		ftp://fr2.rpmfind.net/linux/dag/redhat/9/en/i386/dag/RPMS/
PKGNAMEPREFIX=	linux-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embed MPlayer into browser

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
		${LINUXBASE}/usr/lib/libpangoxft-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango
.if !defined(OVERRIDE_LINUX_BASE_PORT) || \
	(${OVERRIDE_LINUX_BASE_PORT} != "fc6" && \
	${OVERRIDE_LINUX_BASE_PORT} != "f7" && \
	${OVERRIDE_LINUX_BASE_PORT} != "f8")
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libgobject-2.0.so.0:${PORTSDIR}/devel/linux-glib2
.endif

NO_BUILD=	yes
USE_LINUX_RPM=	yes
USE_XLIB=	yes
LINUX_DIST=	fedora
LINUX_DIST_VER=	4
PREFIX?=	${LOCALBASE}
SRC_DISTFILES=

USE_NPAPI=	linux
NPAPI_WRKSRC=	${WRKDIR}/usr/lib/mozilla/plugins
NPAPI_FILES=	${PLUGINS_EXT:S/^/${PORTNAME}/}
PLUGINS_EXT=	.so .xpt -dvx.so -dvx.xpt -qt.so -qt.xpt -rm.so -rm.xpt -wmp.so -wmp.xpt

.include "${.CURDIR}/Makefile.npapi"
.include <bsd.port.mk>

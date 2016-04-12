# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	contractor
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpadlibrarian.net/176424633/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/
DIST_SUBDIR=	eos

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Desktop-wide extension service

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee

USE_GCC=	yes
USES=	cmake pkgconfig
USE_GNOME=	glib20

.include <bsd.port.mk>

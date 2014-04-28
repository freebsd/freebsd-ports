# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/misc/gnome-user-docs/Makefile 19531 2014-04-15 19:25:17Z gusi $

PORTNAME=	gnome-user-docs
PORTVERSION=	3.12.1
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 users guide

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

GNU_CONFIGURE=	yes
USES=		gettext:build gmake pathfix tar:xz
USE_GNOME=	gnomeprefix gnomehier libxml2:build

.include <bsd.port.mk>

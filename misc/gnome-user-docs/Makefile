# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/misc/gnome-user-docs/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	gnome-user-docs
PORTVERSION=	3.14.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 users guide

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

GNU_CONFIGURE=	yes
USES=		gettext-tools gmake pathfix tar:xz
USE_GNOME=	gnomeprefix libxml2:build

.include <bsd.port.mk>

# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/misc/gnome-user-docs3/Makefile 18566 2013-06-18 07:35:39Z kwm $

PORTNAME=	gnome-user-docs
PORTVERSION=	3.6.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 users guide

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USE_XZ=		yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes
USES=		gettext:build gmake pathfix
USE_GNOME=	gnomeprefix gnomehier libxml2:build

.include <bsd.port.mk>

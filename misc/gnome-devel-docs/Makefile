# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/misc/gnome-devel-docs/Makefile 19639 2014-05-13 05:37:44Z gusi $

PORTNAME=	gnome-devel-docs
PORTVERSION=	3.12.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documents targeted for GNOME developers

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
#RUN_DEPENDS=	gnome-doc-prepare:${PORTSDIR}/textproc/gnome-doc-utils

USES=		gmake pkgconfig tar:xz
USE_GNOME=	gnomehier
GNU_CONFIGURE=	yes

.include <bsd.port.mk>

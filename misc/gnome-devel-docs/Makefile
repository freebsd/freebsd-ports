# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/misc/gnome-devel-docs/Makefile 19527 2014-04-15 09:54:06Z gusi $

PORTNAME=	gnome-devel-docs
PORTVERSION=	3.12.1
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

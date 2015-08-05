# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-devel-docs
PORTVERSION=	3.16.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documents targeted for GNOME developers

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext-tools gmake pkgconfig tar:xz
GNU_CONFIGURE=	yes

.include <bsd.port.mk>

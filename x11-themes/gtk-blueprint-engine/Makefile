# Created by: sk8harddiefast
# $FreeBSD$

PORTNAME=	blueprint
PORTVERSION=	0.9.20
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://dlc.sun.com/osol/jds/downloads/extras/
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine

MAINTAINER=	sk8harddiefast@gmail.com
COMMENT=	Engine, and collection of icons, themes from OpenSolaris

LICENSE=	GPLv2

BUILD_DEPENDS=	icon-naming-utils>=0.8.90:${PORTSDIR}/x11-themes/icon-naming-utils

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake libtool:keepla perl5 pkgconfig
USE_GNOME=	glib20 gtk20 intltool intlhack
INSTALLS_ICONS=	yes

.include <bsd.port.mk>

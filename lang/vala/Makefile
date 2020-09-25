# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vala
PORTVERSION=	0.48.10
PORTEPOCH=	1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

LICENSE=	LGPL21

PORTSCOUT=	limitw:1,even

USES=		bison gettext-runtime gmake gnome libtool \
		localbase pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix libxslt:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-valadoc
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>

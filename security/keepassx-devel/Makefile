# Created by: Eric Camachat <eric@camachat.org>
# $FreeBSD$

PORTNAME=	keepassx
PORTVERSION=	2.0.3
PORTREVISION=	7
CATEGORIES=	security
PKGNAMESUFFIX=	-devel

MAINTAINER=	eric@camachat.org
COMMENT=	Cross Platform Password Manager

LICENSE=	BOOST-1.0 BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL21 LGPL3 NOKIA-LGPL-EXCEPTION
LICENSE_COMB=	multi
LICENSE_NAME_BOOST-1.0=	Boost Software License version 1.0
LICENSE_NAME_NOKIA-LGPL-EXCEPTION=	Nokia Qt LGPL Exception version 1.1
LICENSE_FILE_BOOST-1.0=	${WRKSRC}/LICENSE.BOOST-1.0
LICENSE_FILE_NOKIA-LGPL-EXCEPTION=	${WRKSRC}/LICENSE.NOKIA-LGPL-EXCEPTION
LICENSE_PERMS_BOOST-1.0=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_NOKIA-LGPL-EXCEPTION=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

CONFLICTS_INSTALL=	keepassx-0.* keepassx2-* keepassxc-*

USES=		cmake compiler:c++11-lib desktop-file-utils qt:5 \
		shared-mime-info xorg
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT=		buildtools_build concurrent core gui linguisttools qmake_build \
		testlib widgets x11extras
USE_XORG=	ice xorgproto sm x11 xcursor xext xfixes xi xrandr xrender \
		xt xtst

USE_GITHUB=	yes
GH_TAGNAME=	55869e8

CMAKE_ARGS+=	-DZLIB_SUPPORTS_GZIP:BOOL=ON

.include <bsd.port.mk>

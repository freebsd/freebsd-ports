# Created by: Eric Camachat <eric@camachat.org>
# $FreeBSD$

PORTNAME=	keepassx
PORTVERSION=	2.0.3
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	security
MASTER_SITES=	https://www.keepassx.org/releases/${PORTVERSION}/
PKGNAMESUFFIX=	2

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

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

CONFLICTS_INSTALL=	keepassx-0.* keepassx-devel-* keepassxc-*

USES=		cmake compiler:features desktop-file-utils qt:4 shared-mime-info
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT=		corelib gui xml qtestlib uic_build moc_build \
		qmake_build rcc_build linguisttools
USE_XORG=	ice xorgproto sm x11 xcursor xext xfixes xi xrandr xrender \
		xt xtst

.include <bsd.port.pre.mk>

.if !${COMPILER_FEATURES:Mc++0x}
CMAKE_ARGS+=	-DWITH_CXX11:BOOL=OFF
.endif
CMAKE_ARGS+=	-DZLIB_SUPPORTS_GZIP:BOOL=ON

.include <bsd.port.post.mk>

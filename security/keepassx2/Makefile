# Created by: Eric Camachat <eric@camachat.org>
# $FreeBSD$

PORTNAME=	keepassx
PORTVERSION=	2.0.2
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	security
MASTER_SITES=	https://www.keepassx.org/releases/${PORTVERSION}/
PKGNAMESUFFIX=	2

MAINTAINER=	eric@camachat.org
COMMENT=	Cross Platform Password Manager

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

CONFLICTS_INSTALL=	keepassx-0.*

USES=		cmake compiler:features desktop-file-utils shared-mime-info
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	corelib gui xml qtestlib uic_build moc_build \
		qmake_build rcc_build linguisttools
USE_XORG=	ice inputproto sm x11 xcursor xext xfixes xi xrandr xrender \
		xt xtst

.include <bsd.port.pre.mk>

.if !${COMPILER_FEATURES:Mc++0x}
CMAKE_ARGS+=	-DWITH_CXX11:BOOL=OFF
.endif

.include <bsd.port.post.mk>

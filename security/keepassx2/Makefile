# Created by: Eric Camachat <eric@camachat.org>
# $FreeBSD$

PORTNAME=	keepassx
DISTVERSION=	2.0-beta2
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	https://www.keepassx.org/dev/attachments/download/115/
PKGNAMESUFFIX=	2

MAINTAINER=	eric@camachat.org
COMMENT=	Cross Platform Password Manager

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

CONFLICTS_INSTALL=	keepassx-0.*

USES=		cmake desktop-file-utils shared-mime-info
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	corelib gui xml qtestlib uic_build moc_build \
		qmake_build rcc_build linguisttools
USE_XORG=	ice inputproto sm x11 xcursor xext xfixes xi xrandr xrender \
		xt xtst

.include <bsd.port.mk>

# Created by: Eric Camachat <eric@camachat.org>
# $FreeBSD$

PORTNAME=	KeePassX
DISTVERSION=	2.0
CATEGORIES=	security
MASTER_SITES=	https://www.keepassx.org/dev/attachments/download/36/
PKGNAMESUFFIX=	-alpha
DISTNAME=	${PORTNAME:L}-${DISTVERSION}${PKGNAMESUFFIX}4

MAINTAINER=	eric@camachat.org
COMMENT=	Cross Platform Password Manager

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt

CONFLICTS_INSTALL=	keepassx-0.*

DATADIR=	${PREFIX}/share/${PORTNAME:L}
WRKSRC=		${WRKDIR}/${DISTNAME:L}

USES=		cmake
USE_GCC=	4.2+
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	corelib gui xml qtestlib dbus uic_build moc_build \
		qmake_build rcc_build
USE_XORG=	xt inputproto xtst xrender xrandr xfixes xcursor \
		xext x11 sm ice xi

.include <bsd.port.mk>

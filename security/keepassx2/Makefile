# Created by: Eric Camachat <eric@camachat.org>
# $FreeBSD$

PORTNAME=	KeePassX
DISTVERSION=	2.0
CATEGORIES=	security
MASTER_SITES=	https://www.keepassx.org/dev/attachments/download/69/
PKGNAMESUFFIX=	-alpha
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}${PKGNAMESUFFIX}6

MAINTAINER=	eric@camachat.org
COMMENT=	Cross Platform Password Manager

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

CONFLICTS_INSTALL=	keepassx-0.*

DATADIR=	${PREFIX}/share/${PORTNAME:tl}
WRKSRC=		${WRKDIR}/${DISTNAME:tl}

USES=		cmake
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	corelib gui xml qtestlib dbus uic_build moc_build \
		qmake_build rcc_build
USE_XORG=	xt inputproto xtst xrender xrandr xfixes xcursor \
		xext x11 sm ice xi

.include <bsd.port.mk>

PORTNAME=	rtkit-unix
DISTVERSION=	0.20250505
CATEGORIES=	sysutils deskutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	C++/Qt implementation of the org.freedesktop.RealtimeKit1 D-Bus interface
WWW=		https://github.com/arrowd/rtkit-unix/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpolkit-qt6-core-1.so:sysutils/polkit-qt-1@qt6

USES=		cmake qt:6

USE_QT=		base

USE_GITHUB=	yes
GH_ACCOUNT=	arrowd
GH_TAGNAME=	e4465ba18d43e13af35f075e75056e11200867c5

PLIST_FILES=	libexec/rtkit-daemon \
		share/dbus-1/system-services/org.freedesktop.RealtimeKit1.service \
		share/dbus-1/system.d/org.freedesktop.RealtimeKit1.conf \
		share/polkit-1/actions/org.freedesktop.RealtimeKit1.policy

.include <bsd.port.mk>

PORTNAME=	Quaternion
DISTVERSION=	0.0.95.1
PORTREVISION=	2
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM client based on Qt technologies
WWW=		https://github.com/quotient-im/Quaternion/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5 \
		libsecret-1.so:security/libsecret \
		libolm.so:security/olm
BUILD_DEPENDS=	libquotient>=0.8:net-im/libquotient
# Quotient is a static lib, doesn't need to be in RUN_DEPENDS

USES=		cmake compiler:c++17-lang desktop-file-utils \
		gettext-runtime gnome \
		localbase:ldflags qt:5 tar:xz
USE_GNOME=	glib20
USE_QT=		core dbus declarative gui multimedia network \
		quickcontrols quickcontrols2 sql widgets \
		buildtools:build linguist:build qmake:build

CMAKE_OFF=	BUILD_WITH_QT6

USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im
GH_TAGNAME=	447d8ec4f990499fb589a37b7e8eae8c6781cadc

.include <bsd.port.mk>

PORTNAME=	Quaternion
DISTVERSION=	0.0.95.1
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM client based on Qt technologies
WWW=		https://github.com/quotient-im/Quaternion/

BROKEN=		No upstream release compatible with libquotient 0.7 yet

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5 \
		libsecret-1.so:security/libsecret
BUILD_DEPENDS=	libquotient>=0.7:net-im/libquotient
# Quotient is a static lib, doesn't need to be in RUN_DEPENDS

USES=		cmake compiler:c++17-lang gettext-runtime gnome \
		localbase:ldflags qt:5 tar:xz
USE_GNOME=	glib20
USE_QT=		core dbus declarative gui multimedia network widgets \
		quickcontrols quickcontrols2 \
		buildtools:build linguist:build qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im

.include <bsd.port.mk>

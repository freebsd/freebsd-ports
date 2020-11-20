# $FreeBSD$

PORTNAME=	Quaternion
DISTVERSION=	0.0.9.5-beta1
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM client based on Qt technologies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain \
		libsecret-1.so:security/libsecret
BUILD_DEPENDS=	libquotient>=0.6.2:net-im/libquotient

USES=		cmake compiler:c++17-lang gettext-runtime gnome \
		localbase:ldflags qt:5 tar:xz
USE_GNOME=	glib20
USE_QT=		core dbus declarative gui multimedia network widgets \
		quickcontrols_run quickcontrols2_run \
		buildtools_build linguist_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im

.include <bsd.port.mk>

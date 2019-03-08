# $FreeBSD$

PORTNAME=	Quaternion
DISTVERSION=	0.0.9.4
DISTVERSIONSUFFIX=	-beta1
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM client based on Qt technologies

LICENSE=	GPLv3
LICENSE_FILES=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5 \
		libsecret-1.so:security/libsecret
BUILD_DEPENDS=	libqmatrixclient>=0.5:net-im/libqmatrixclient

USES=		cmake compiler:c++17-lang gettext-runtime gnome \
		localbase:ldflags qt:5 tar:xz
USE_GNOME=	glib20
USE_QT=		core dbus declarative gui multimedia network widgets \
		buildtools_build linguist_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	QMatrixClient

.include <bsd.port.mk>

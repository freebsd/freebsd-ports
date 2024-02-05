PORTNAME=	Quaternion
DISTVERSION=	0.0.96
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM client based on Qt technologies
WWW=		https://github.com/quotient-im/Quaternion/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5 \
		libsecret-1.so:security/libsecret \
		libolm.so:security/olm
BUILD_DEPENDS=	libquotient-qt5>=0.8.1.2:net-im/libquotient@qt5
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

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
USES+=	llvm:max=15
.endif

.include <bsd.port.mk>

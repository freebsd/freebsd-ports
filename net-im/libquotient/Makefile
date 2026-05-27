PORTNAME=	libquotient
DISTVERSION=	0.9.6.1
CATEGORIES=	net-im

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Matrix IM support library using Qt technologies
WWW=		https://github.com/quotient-im/libQuotient

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6 \
		libolm.so:security/olm

USES=		cmake compiler:c++20-lang qt:6 tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im
GH_PROJECT=	libQuotient
USE_QT=		base
CMAKE_OFF=	Quotient_INSTALL_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	API_VER=0.9 \
		SHLIB_VER=${DISTVERSION}

.include <bsd.port.mk>

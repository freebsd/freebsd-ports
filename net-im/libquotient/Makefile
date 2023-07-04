PORTNAME=	libquotient
DISTVERSION=	0.8.0
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM support library using Qt technologies
WWW=		https://github.com/quotient-im/libQuotient

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5 \
		libolm.so:security/olm

USES=		cmake compiler:c++20-lang qt:5 tar:xz
USE_QT=		concurrent core gui multimedia network \
		buildtools:build qmake:build testlib:build

CONFLICTS=	libqmatrixclient\*

USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im
GH_PROJECT=	libQuotient

CMAKE_OFF=	Quotient_INSTALL_TESTS
CMAKE_ON=	Quotient_ENABLE_E2EE

.include <bsd.port.options.mk>

# Work around compiler bug, see pr: 272285
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
USES+=		llvm
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}
.endif

.include <bsd.port.mk>

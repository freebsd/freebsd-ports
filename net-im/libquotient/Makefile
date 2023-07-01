PORTNAME=	libquotient
DISTVERSION=	0.7.1
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM support library using Qt technologies
WWW=		https://github.com/quotient-im/libQuotient

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5

USES=		cmake qt:5 tar:xz
USE_QT=		concurrent core gui multimedia network \
		buildtools:build qmake:build testlib:build

CONFLICTS=	libqmatrixclient\*

USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im
GH_PROJECT=	libQuotient

CMAKE_ARGS=	-DQuotient_INSTALL_TESTS=OFF

# Work around compiler bug, see pr: 272285
USES+=		llvm
CC=		${LLVM_PREFIX}/bin/clang
CPP=		${LLVM_PREFIX}/bin/clang-cpp
CXX=		${LLVM_PREFIX}/bin/clang++


.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1301507
CMAKE_ARGS+=	-DBUILD_TESTING=OFF
.endif

.include <bsd.port.post.mk>

PORTNAME=	heaan
DISTVERSION=	2.1-40
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g48a1ed0
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library that implements homomorphic encryption

LICENSE=	CC-BY-3.0
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BROKEN_i386=	error: __int128 is not supported on this target
BROKEN_powerpc=	error: __int128 is not supported on this target
BROKEN_armv6=	error: __int128 is not supported on this target
BROKEN_armv7=	error: __int128 is not supported on this target

LIB_DEPENDS=	libntl.so:math/ntl

USES=		compiler:c++11-lang gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	snucrypto
GH_PROJECT=	${PORTNAME:tu}
USE_LDCONFIG=	yes

MAKEFILE=	makefile

WRKSRC_SUBDIR=	HEAAN/lib

CXXFLAGS+=	-fPIC

BINARY_ALIAS=	g++=${CXX}

post-patch: # for tests, otherwise they try to use static libs
	@${REINPLACE_CMD} 's|-L/usr/local/lib ../lib/libHEAAN.a|$$(CXXFLAGS) $$(LDFLAGS) ../lib/libHEAAN.so|' ${WRKSRC}/../run/makefile

do-install: # no install target: https://github.com/snucrypto/HEAAN/issues/47
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/../src && ${COPYTREE_SHARE} \*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/libHEAAN.so ${STAGEDIR}${PREFIX}/lib

do-test: # available tests are listed in HEAAN/run/test.cpp
	@cd ${WRKSRC}/../run && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} && \
		./TestHEAAN Encrypt && \
		./TestHEAAN EncryptSingle && \
		./TestHEAAN Add && \
		./TestHEAAN Mult && \
		./TestHEAAN iMult && \
		./TestHEAAN RotateFast && \
		./TestHEAAN Conjugate

.include <bsd.port.mk>

PORTNAME=	openssl-agent
PORTVERSION=	0.16.0
CATEGORIES=	security
MASTER_SITES=	https://pkg.cppget.org/1/alpha/build2/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	OpenSSL key agent and client utilities
WWW=		https://git.build2.org/cgit/openssl-agent/tree/README

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	build2>=0:devel/build2
LIB_DEPENDS=	libbutl.so:devel/build2

PLIST_FILES=	bin/openssl-agent-pkcs11 \
		bin/openssl-client

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} b configure \
		config.cxx=${CXX} \
		config.cxx.coptions="${CXXFLAGS}" \
		config.cxx.loptions="${LDFLAGS} ${STRIP}" \
		config.bin.lib=shared \
		config.bin.rpath=${PREFIX}/lib \
		config.install.chroot=${STAGEDIR} \
		config.install.root=${PREFIX}
do-install:
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} b install -V -j ${MAKE_JOBS_NUMBER} -J ${MAKE_JOBS_NUMBER}

.include <bsd.port.mk>

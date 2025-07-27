PORTNAME=	oqsprovider
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	security
PKGNAMEPREFIX=	openssl-

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	quantum-resistant cryptography provider for OpenSSL
WWW=		https://openquantumsafe.org/applications/tls.html#oqs-openssl-provider

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	liboqs.so:security/liboqs
TEST_ENVIRONMENT=	OPENSSL_INSTALL=${LOCALBASE}/bin/openssl

USES=		cmake:testing ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	open-quantum-safe
GH_PROJECT=	oqs-provider

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Debug\
		-DOPENSSL_ROOT_DIR=${OPENSSLBASE} \
		-DCMAKE_PREFIX_PATH=${OPENSSL_PATH} 

SUB_FILES=	oqsprovider.cnf pkg-message

PLIST_FILES=	include/oqs-provider/oqs_prov.h \
		lib/ossl-modules/oqsprovider.so \
		openssl/oqsprovider.cnf

.include <bsd.port.pre.mk>

.if !defined(OPENSSL_PORT) && ${OSVERSION} < 1400000
BROKEN=	Requires OpenSSL 3.0+, preferably 3.2+
.endif

post-install:
.if ${OPENSSLLIB} == "/usr/lib"
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ossl-modules
	${MV} ${STAGEDIR}/usr/lib/ossl-modules/oqsprovider.so ${STAGEDIR}${PREFIX}/lib/ossl-modules
	echo "@dir /usr/lib/ossl-modules" >> ${TMPPLIST}
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/openssl
	${INSTALL_DATA} ${WRKDIR}/oqsprovider.cnf ${STAGEDIR}${PREFIX}/openssl/

.include <bsd.port.post.mk>

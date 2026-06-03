PORTNAME=	pkcs11provider
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	openssl-

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	OpenSSL 3.x PKCS\#11 provider
WWW=		https://github.com/latchset/pkcs11-provider

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSES/Apache-2.0.txt

USES=		meson ssl
USE_LDCONFIG=	yes

TEST_ENVIRONMENT=	OPENSSL_INSTALL=${LOCALBASE}/bin/openssl

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

MESON_ARGS=	--libdir ${PREFIX} \
		-Dmodulesdir="${PREFIX}/lib/ossl-modules"

USE_GITHUB=	yes
GH_ACCOUNT=	latchset
GH_PROJECT=	pkcs11-provider

SUB_FILES=	pkcs11provider.cnf

PLIST_FILES=	lib/ossl-modules/pkcs11.so \
		openssl/pkcs11provider.cnf \
		share/man/man7/provider-pkcs11.7.gz 
#		@comment\ @dir\ /usr/lib/ossl-modules

.include <bsd.port.pre.mk>

.if !defined(OPENSSL_PORT) && ${OSVERSION} < 1400000
BROKEN=	requires OpenSSL 3.0+, preferably 3.2+
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/openssl
	${INSTALL_DATA} ${WRKDIR}/pkcs11provider.cnf ${STAGEDIR}${PREFIX}/openssl/

.include <bsd.port.post.mk>

# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	openssl_tpm_engine
PORTVERSION=	0.4.2
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF/trousers/OpenSSL%20TPM%20Engine/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	OpenSSL TPM engine

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/sbin/tcsd:security/trousers
LIB_DEPENDS=	libtspi.so:security/trousers

USES=		autoreconf gmake libtool ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto -L${LOCALBASE}/lib
CFLAGS+=	-I${OPENSSLINC} -I${LOCALBASE}/include
SUB_FILES=	pkg-message
PLIST_FILES=	bin/create_tpm_key \
		lib/openssl/engines/libtpm.so \
		lib/openssl/engines/libtpm.so.0 \
		lib/openssl/engines/libtpm.so.0.0.0
INSTALL_TARGET=	install-strip
PORTEXAMPLES=	openssl.cnf.sample

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE=	Detected LibreSSL (RAND_METHOD structure unsupported)
.endif

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/openssl.cnf.sample

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/openssl.cnf.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>

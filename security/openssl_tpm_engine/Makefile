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

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lcrypto
CFLAGS+=	-I${LOCALBASE}/include
SUB_FILES=	pkg-message
PLIST_FILES=	bin/create_tpm_key \
		lib/openssl/engines/libtpm.so \
		lib/openssl/engines/libtpm.so.0 \
		lib/openssl/engines/libtpm.so.0.0.0
INSTALL_TARGET=	install-strip
PORTEXAMPLES=	openssl.cnf.sample

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/openssl.cnf.sample

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/openssl.cnf.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

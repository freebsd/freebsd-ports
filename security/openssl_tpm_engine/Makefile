# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	openssl_tpm_engine
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	OpenSSL TPM engine

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/sbin/tcsd:security/trousers
LIB_DEPENDS=	libtspi.so:security/trousers

USES=		autoreconf gmake libtool localbase ssl pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	mgerstner
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl="${OPENSSLBASE}"
SUB_FILES=	pkg-message
PLIST_FILES=	bin/create_tpm_key \
		lib/openssl/engines/tpm.so
INSTALL_TARGET=	install-strip
PORTEXAMPLES=	openssl.cnf.sample

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE=	Detected LibreSSL (RAND_METHOD structure unsupported)
.endif

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/dist/openssl.cnf.sample

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/openssl.cnf.sample \
	    ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>

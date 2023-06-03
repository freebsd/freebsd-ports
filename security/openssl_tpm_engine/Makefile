PORTNAME=	openssl_tpm_engine
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	OpenSSL TPM engine
WWW=		https://github.com/mgerstner/openssl_tpm_engine

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Requires older openssl and upstream unmaintained since 2017
EXPIRATION_DATE=	2023-07-02
BROKEN_SSL=		openssl30 openssl31
BROKEN_SSL_REASON=	Requires openssl 1.0.x or 1.1.x
IGNORE_SSL=		libressl libressl-devel
IGNORE_SSL_REASON=	Detected LibreSSL (RAND_METHOD structure unsupported)

LIB_DEPENDS=	libtspi.so:security/trousers
RUN_DEPENDS=	${LOCALBASE}/sbin/tcsd:security/trousers

USES=		autoreconf gmake libtool localbase ssl pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	mgerstner
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl="${OPENSSLBASE}" \
		--with-enginedir="${PREFIX}/lib/openssl/engines"
SUB_FILES=	pkg-message
PLIST_FILES=	bin/create_tpm_key
INSTALL_TARGET=	install-strip
PORTEXAMPLES=	openssl.cnf.sample

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	(${CAT} ${OPENSSLINC}/openssl/opensslv.h; \
	 ${ECHO_CMD} "#if OPENSSL_VERSION_NUMBER < 0x10100000L"; \
	 ${ECHO_CMD} "lib/openssl/engines/libtpm.so"; \
	 ${ECHO_CMD} "#else"; \
	 ${ECHO_CMD} "lib/openssl/engines/tpm.so"; \
	 ${ECHO_CMD} "#endif"; \
	) | ${CPP} | ${GREP} -v \# > ${WRKDIR}/.tpmso; \
	${REINPLACE_CMD} "s|%%TPMSO%%|${PREFIX}/$$(cat ${WRKDIR}/.tpmso)|g" \
	    ${WRKSRC}/dist/openssl.cnf.sample

.if defined(INSTALL_AS_USER)
_T=|| ${TRUE}
.endif
post-install:
	(${CAT} ${WRKDIR}/.tpmso; \
	${ECHO_CMD} "@postexec /usr/sbin/service ldconfig restart > /dev/null ${_T}" >> ${TMPPLIST}; \
	${ECHO_CMD} "@postunexec /usr/sbin/service ldconfig restart > /dev/null ${_T}" >> ${TMPPLIST}; \
	) >> ${TMPPLIST}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/openssl.cnf.sample \
	    ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

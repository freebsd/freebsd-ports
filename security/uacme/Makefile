# $FreeBSD$

PORTNAME=	uacme
DISTVERSIONPREFIX=	upstream/
DISTVERSION=	1.7
CATEGORIES=	security www

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Lightweight C ACMEv2 client which uses external authenticators

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ndilieto
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${EXAMPLESDIR:H} \
		--disable-maintainer-mode \
		--sysconfdir=${PREFIX}/etc

OPTIONS_DEFINE=		DOCS EXAMPLES MANPAGES UALPN
_OPENSSL_SAFE=		${(${OPSYS} == FreeBSD && ${OSVERSION} < 1200085 && ${SSL_DEFAULT} == base) || ${SSL_DEFAULT} == libressl || ${SSL_DEFAULT} == libressl-devel:?no:yes}
OPTIONS_DEFAULT=	${${_OPENSSL_SAFE} == no:?GNUTLS:OPENSSL} MANPAGES \
			UALPN
OPTIONS_SINGLE=		CRYPTO
OPTIONS_SINGLE_CRYPTO=	GNUTLS MBEDTLS OPENSSL
OPTIONS_EXCLUDE=	${${_OPENSSL_SAFE} == no:?OPENSSL:}
OPTIONS_SUB=		yes

CRYPTO_DESC=	Crypto library
UALPN_DESC=	Install the proxying ACMEv2 tls-alpn-01 responder ualpn(1)

GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=		gnutls
MANPAGES_BUILD_DEPENDS=		asciidoc:textproc/asciidoc
MANPAGES_CONFIGURE_ENABLE=	docs
MBEDTLS_BROKEN=			needs mbedtls >= 2.25, 2.16.x lacks mbedtls_x509_crt_parse_der_with_ext_cb support
MBEDTLS_LIB_DEPENDS=		libmbedtls.so:security/mbedtls
MBEDTLS_CONFIGURE_WITH=		mbedtls=${LOCALBASE}
OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_WITH=		openssl=${OPENSSLBASE}
UALPN_CONFIGURE_WITH=		ualpn

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

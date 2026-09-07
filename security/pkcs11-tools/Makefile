PORTNAME=	pkcs11-tools
DISTVERSION=	3.1.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	eric.devolder@gmail.com
COMMENT=	Tools for managing PKCS11 cryptographic tokens
WWW=		https://github.com/Mastercard/pkcs11-tools

LICENSE=	APACHE20 THIRDPARTY
LICENSE_COMB=	multi
LICENSE_NAME_THIRDPARTY=	Third-party licenses
LICENSE_FILE_THIRDPARTY=	${WRKSRC}/docs/TPLICENSES.md
LICENSE_PERMS_THIRDPARTY=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	autoconf-archive>0:devel/autoconf-archive \
		flex:textproc/flex

USES=		autoreconf:build bison compiler:c11 gmake libtool:build pkgconfig ssl

IGNORE_SSL=	libressl openssl111 openssl34
IGNORE_SSL_REASON_openssl111=	No support for OpenSSL 3.X providers
IGNORE_SSL_REASON_libressl=	No support for OpenSSL 3.X providers
IGNORE_SSL_REASON_openssl34=	No support for PQC algotithms

USE_GITHUB=	nodefault
GH_ACCOUNT=	Mastercard
GH_TUPLE=	coreutils:gnulib:34e1754363:gnulib \
		oasis-tcs:pkcs11:858bfc8:oasis_pkcs11

GNU_CONFIGURE=	yes

MAKE_ENV=	LIBCRYPTO_RPATH=${OPENSSLBASE}/lib

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	BASH DOCS MANPAGES ZSH
OPTIONS_DEFAULT=BASH MANPAGES ZSH
OPTIONS_SUB=	yes
ZSH_IMPLIES=	BASH

post-extract:
	@${RM} -r ${WRKSRC}/.gnulib ${WRKSRC}/include/oasis-pkcs11
	@${MV} ${WRKSRC_gnulib} ${WRKSRC}/.gnulib
	@${MV} ${WRKSRC_oasis_pkcs11} ${WRKSRC}/include/oasis-pkcs11

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/README.md \
		${WRKSRC}/docs/INSTALL.md \
		${WRKSRC}/docs/MANUAL.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

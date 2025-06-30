PORTNAME=	nettle
PORTVERSION=	3.10.2
CATEGORIES=	security
MASTER_SITES=	GNU \
		https://www.lysator.liu.se/~nisse/archive/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-level cryptographic library
WWW=		https://www.lysator.liu.se/~nisse/nettle/

LICENSE=	GPLv2+ LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYINGv2
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LESSERv3

BUILD_DEPENDS=	gmp>=6.1.0:math/gmp
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		compiler:c11 cpe gmake localbase pathfix

CONFIGURE_ARGS=	--enable-ld-version-script --enable-shared
CONFIGURE_ENV=	M4="/usr/bin/m4 -g"
GNU_CONFIGURE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes

INFO=		nettle

CPE_VENDOR=	nettle_project

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_CFLAGS=	-I${OPENSSLINC}
EXAMPLES_USES=		ssl
EXAMPLES_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-Makefile.in

.include <bsd.port.options.mk>

.if ${ARCH} == "mips64"
post-patch:
	@${REINPLACE_CMD} -e 's|__sgi|__unix__|' ${WRKSRC}/configure
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so
	${INSTALL_DATA} ${WRKSRC}/nettle.info ${STAGEDIR}${PREFIX}/${INFO_PATH}/nettle.info

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} NEWS README nettle.html nettle.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_PROGRAM} base16dec base16enc base64dec base64enc ecc-benchmark hogweed-benchmark nettle-benchmark random-prime rsa-decrypt rsa-encrypt rsa-keygen rsa-sign rsa-verify ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.[ch] ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

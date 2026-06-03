PORTNAME=	libsodium
#################################################
# Make sure to bump all consumers when updating #
#################################################
DISTVERSION=	1.0.22
CATEGORIES=	security
MASTER_SITES=	https://github.com/jedisct1/${PORTNAME}/releases/download/${DISTVERSION}-RELEASE/ \
		https://download.libsodium.org/${PORTNAME}/releases/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Library to build higher-level cryptographic tools
WWW=		https://github.com/jedisct1/libsodium/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool pathfix pkgconfig tar:bz2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS+=	-ftree-vectorize \
				-ftree-slp-vectorize \
				-fomit-frame-pointer

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/THANKS ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

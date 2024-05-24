PORTNAME=	libsodium
#################################################
# Make sure to bump all consumers when updating #
#################################################
PORTVERSION=	1.0.19
CATEGORIES=	security
MASTER_SITES=	https://download.libsodium.org/libsodium/releases/

PATCH_SITES=	https://github.com/jedisct1/libsodium/commit/
PATCHFILES=	bb6e6a4b527194e3ca8e8bc7e96b166b361853e3.patch:-p1 # aarch64 build fix

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Library to build higher-level cryptographic tools
WWW=		https://github.com/jedisct1/libsodium/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

WRKSRC=		${WRKDIR}/${PORTNAME}-stable

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/THANKS ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

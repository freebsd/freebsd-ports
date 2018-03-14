# $FreeBSD$

PORTNAME=	libsodium
PORTVERSION=	1.0.16
CATEGORIES=	security
MASTER_SITES=	https://download.libsodium.org/libsodium/releases/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Library to build higher-level cryptographic tools

LICENSE=	ISCL

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
TEST_TARGET=	check

CONFIGURE_ARGS+=	--enable-blocking-random
INSTALL_TARGET?=	install-strip
TEST_TARGET=		check

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/THANKS ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

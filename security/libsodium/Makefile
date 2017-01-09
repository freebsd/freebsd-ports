# $FreeBSD$

PORTNAME=	libsodium
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://download.libsodium.org/libsodium/releases/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Library to build higher-level cryptographic tools

LICENSE=	ISCL

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig compiler:c11
USE_LDCONFIG=	yes
TEST_TARGET=	check

CONFIGURE_ARGS+=	--enable-blocking-random
INSTALL_TARGET?=	install-strip

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/THANKS ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

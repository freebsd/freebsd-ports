PORTNAME=	mhash
PORTVERSION=	0.9.9.9
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy-to-use library for strong hashes such as MD5 and SHA1
WWW=		https://mhash.sourceforge.net/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-static --with-gnu-ld
TEST_TARGET=	check

PORTDOCS=	example.c skid2-authentication

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmhash.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

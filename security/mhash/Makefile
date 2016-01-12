# Created by: nsayer@FreeBSD.org
# $FreeBSD$

PORTNAME=	mhash
PORTVERSION=	0.9.9.9
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy-to-use library for strong hashes such as MD5 and SHA1

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-static --with-gnu-ld
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

PORTDOCS=	example.c skid2-authentication

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmhash.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

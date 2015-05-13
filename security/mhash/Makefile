# Created by: nsayer@FreeBSD.org
# $FreeBSD$

PORTNAME=	mhash
PORTVERSION=	0.9.9.9
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy-to-use library for strong hashes such as MD5 and SHA1

LICENSE=	LGPL20 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2 libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-static --with-gnu-ld

PORTDOCS=	example.c skid2-authentication

test:	build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmhash.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

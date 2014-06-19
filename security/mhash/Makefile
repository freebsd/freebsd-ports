# Created by: nsayer@FreeBSD.org
# $FreeBSD$

PORTNAME=	mhash
PORTVERSION=	0.9.9.9
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy-to-use library for strong hashes such as MD5 and SHA1

USES=		tar:bzip2 libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-static --with-gnu-ld
INSTALL_TARGET=	install-strip

PORTDOCS=	example.c skid2-authentication

test:	build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

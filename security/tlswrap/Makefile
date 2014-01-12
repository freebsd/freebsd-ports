# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	tlswrap
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.tlswrap.com/
DISTNAME=	${PORTNAME}-1.04

MAINTAINER=	johans@FreeBSD.org
COMMENT=	FTP proxy that wraps data and control with TLS/SSL

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

post-patch:
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS|LDFLAGS).*=,\1?=,g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E 's,pipe([12]),pipe0\1,g' \
		${WRKSRC}/misc.[ch] ${WRKSRC}/network.c ${WRKSRC}/tlswrap.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tlswrap ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

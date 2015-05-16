# Created by: Piotr Smyrak <smyru@heron.pl> and
# $FreeBSD$

PORTNAME=	libtlen
PORTVERSION=	20041113
PORTREVISION=	1
CATEGORIES=	polish net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backend for interoperability with Tlen.pl, Polish IM network

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtlen.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in libtlen.html libtlen.css AUTHORS TODO
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

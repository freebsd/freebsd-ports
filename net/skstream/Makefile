# Created by: Janni
# $FreeBSD$

PORTNAME=	skstream
PORTVERSION=	0.3.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28network%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	An iostream based C++ socket library

USE_GMAKE=	yes
USES=		pathfix pkgconfig compiler:c++11-lib
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| install-docdataDATA | |g'  ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README COPYING AUTHORS NEWS README.FreeSockets
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# Created by: Janni
# $FreeBSD$

PORTNAME=	skstream
PORTVERSION=	0.3.9
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28network%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	iostream based C++ socket library

USES=		libtool pathfix pkgconfig compiler:c++11-lib gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's| install-docdataDATA | |g'  ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README COPYING AUTHORS NEWS README.FreeSockets
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

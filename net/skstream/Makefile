# Created by: Janni
# $FreeBSD$

PORTNAME=	skstream
PORTVERSION=	0.3.9
CATEGORIES=	net
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28network%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	An iostream based C++ socket library

USE_GMAKE=	yes
USES=	pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GCC=	4.7+

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| install-docdataDATA | |g'  ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS NEWS README.FreeSockets
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

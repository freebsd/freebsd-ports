# New ports collection makefile for:   skstream
# Date created:        3 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	skstream
PORTVERSION=	0.3.6
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28network%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	An iostream based C++ socket library

USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's| install-docdataDATA | |g'  ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS NEWS README.FreeSockets
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

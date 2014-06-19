# Created by: ijliao
# $FreeBSD$

PORTNAME=	libntlm
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.nongnu.org/libntlm/releases/

MAINTAINER=	jochen@daten-chaos.de
COMMENT=	Library that implement Microsoft's NTLM authentication

LICENSE=	LGPL21

USES=		pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

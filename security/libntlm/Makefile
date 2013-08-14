# Created by: ijliao
# $FreeBSD$

PORTNAME=	libntlm
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://www.nongnu.org/libntlm/releases/

MAINTAINER=	jochen@daten-chaos.de
COMMENT=	Library that implement Microsoft's NTLM authentication

LICENSE=	LGPL21

USES=	pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

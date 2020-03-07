# Created by: ijliao
# $FreeBSD$

PORTNAME=	libntlm
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	http://www.nongnu.org/libntlm/releases/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library that implement Microsoft's NTLM authentication

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

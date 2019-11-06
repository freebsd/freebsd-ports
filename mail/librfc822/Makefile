# Created by: ijliao
# $FreeBSD$

PORTNAME=	librfc822
PORTVERSION=	1.2
CATEGORIES=	mail devel
MASTER_SITES=	http://cryp.to/librfc2822/

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	Complete parser for RFC822 addresses

BROKEN=		unfetchable

GNU_CONFIGURE=	yes

PORTDOCS=	user-manual.html
PLIST_FILES=	include/rfc822.hpp lib/librfc822.a

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/rfc822.hpp ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/librfc822.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

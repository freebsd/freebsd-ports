PORTNAME=	add-css-links
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://aaronland.info/xsl/xhtml/add-css-links/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add one or more CSS <link> elements to an XHTML document

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/xhtml

PLIST_FILES=	share/xsl/xhtml/add-css-links.xsl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsl/xhtml
	${CP} ${WRKSRC}/*.xsl ${STAGEDIR}${PREFIX}/share/xsl/xhtml/

.include <bsd.port.mk>

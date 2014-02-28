# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	decss
PORTVERSION=	1.0
CATEGORIES=	www perl5
MASTER_SITES=	http://www.pigdog.org/decss/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strip cascading style sheets from webpages

WRKSRC=		${WRKDIR}/source

USES=		perl5 shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/decss
PORTDOCS=	FAQ README decss-now.png decss_mirror.html \
		original_pigdog_article.txt
SHEBANG_FILES=	DeCSS

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/DeCSS ${STAGEDIR}${PREFIX}/bin/decss
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	decss
PORTVERSION=	1.1
CATEGORIES=	www perl5
MASTER_SITES=	http://www.pigdog.org/decss/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strip cascading style sheets from webpages

LICENSE=	ART10

WRKSRC=		${WRKDIR}/source

USES=		perl5 shebangfix
SHEBANG_FILES=	DeCSS
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/decss
PORTDOCS=	FAQ README decss-now.png decss_mirror.html \
		original_pigdog_article.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/DeCSS ${STAGEDIR}${PREFIX}/bin/decss

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

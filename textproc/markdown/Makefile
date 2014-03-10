# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	markdown
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	http://daringfireball.net/projects/downloads/
DISTNAME=	Markdown_${PORTVERSION}

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A text-to-HTML conversion tool for web writers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.text

NO_BUILD=	yes
USES=		shebangfix perl5 zip
SHEBANG_FILES=	Markdown.pl

OPTIONS_DEFINE=	DOCS

PORTDOCS=	Markdown-Readme.text

PLIST_FILES=	bin/markdown

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Markdown.pl ${STAGEDIR}${PREFIX}/bin/markdown
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} "${WRKSRC}/Markdown Readme.text" ${STAGEDIR}${DOCSDIR}/Markdown-Readme.text

.include <bsd.port.mk>

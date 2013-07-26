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

USE_ZIP=	yes
USE_PERL5=	yes
NO_BUILD=	yes
USES=		shebangfix
SHEBANG_FILES=	Markdown.pl

.if !defined(NOPORTDOCS)
PORTDOCS=	License.text Markdown-Readme.text
.endif

PLIST_FILES=	bin/markdown

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Markdown.pl ${PREFIX}/bin/markdown
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} "${WRKSRC}/License.text" ${DOCSDIR}/License.text
	${INSTALL_DATA} "${WRKSRC}/Markdown Readme.text" ${DOCSDIR}/Markdown-Readme.text
.endif

.include <bsd.port.mk>

# Created by: king@v2project.com
# $FreeBSD$

PORTNAME=	makefaq
PORTVERSION=	2.5
CATEGORIES=	textproc python
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makefaq is a Python program that creates a (FAQ)

USES=		python
NO_BUILD=	yes

PLIST_FILES=	bin/makefaq.py man/man1/makefaq.1.gz
PORTDOCS=	README UPGRADING faq.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makefaq.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/makefaq.1  ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

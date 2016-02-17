# Created by: king@v2project.com
# $FreeBSD$

PORTNAME=	makefaq
PORTVERSION=	2.5
CATEGORIES=	textproc python
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makefaq is a Python program that creates a (FAQ)

LICENSE=	GPLv2+

USES=		python tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/makefaq.py man/man1/makefaq.1.gz
PORTDOCS=	BUGS CREDITS ChangeLog README TODO UPGRADING faq.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makefaq.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/makefaq.1  ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

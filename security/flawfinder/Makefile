# Created by: ijliao
# $FreeBSD$

PORTNAME=	flawfinder
PORTVERSION=	1.27
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/security

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Examines source code looking for security weaknesses

USES=		python
NO_BUILD=	yes

PLIST_FILES=	bin/flawfinder man/man1/flawfinder.1.gz
PORTDOCS=	ChangeLog README flawfinder.pdf flawfinder.ps
PORTEXAMPLES=	test.c correct-results.html correct-results.txt

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

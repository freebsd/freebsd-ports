# $FreeBSD$

PORTNAME=	setaudit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	security

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Tool to specify audit configurations on a process

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	csjayp

PLIST_FILES=	bin/setaudit \
		man/man8/setaudit.8.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/setaudit

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

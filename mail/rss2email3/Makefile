# $FreeBSD$

PORTNAME=	rss2email
PORTVERSION=	3.8
DISTVERSIONPREFIX=	v
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	srg@guglielmo.us
COMMENT=	Emails posts from subscribed RSS/Atom newsfeeds

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=5.0.1:textproc/py-feedparser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>=3.0.1:textproc/py-html2text@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	wking

USES=		python:3.3+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	py*-rss2email-2.*

PORTDOCS=	AUTHORS CHANGELOG README
OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/r2e.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

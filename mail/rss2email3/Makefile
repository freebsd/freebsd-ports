# $FreeBSD$

PORTNAME=	rss2email
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	srg@guglielmo.us
COMMENT=	Emails posts from subscribed RSS/Atom newsfeeds

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=5.0.1:textproc/py-feedparser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>=3.0.1:textproc/py-html2text@${FLAVOR}

USES=		python:3.3+
USE_GITHUB=	yes
GH_ACCOUNT=	wking
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

CONFLICTS_INSTALL=	py*-rss2email-2.*

PORTDOCS=	AUTHORS CHANGELOG README
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	man/man1/r2e.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/r2e.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

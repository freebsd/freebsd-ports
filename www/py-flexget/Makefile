# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flexget
PORTVERSION=	1.2.348
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FlexGet-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Program to automate downloading from different sources

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paver>=0:devel/py-paver
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=5.1.3:textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy07>=0.7.5:databases/py-sqlalchemy07 \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_SITELIBDIR}/BeautifulSoup.py:www/py-beautifulsoup32 \
		${PYTHON_SITELIBDIR}/bs4/__init__.py:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.11:www/py-html5lib \
		${PYTHON_PKGNAMEPREFIX}rss2gen>0:textproc/py-rss2gen \
		${PYTHON_PKGNAMEPREFIX}pynzb>0:news/py-pynzb \
		${PYTHON_PKGNAMEPREFIX}progressbar>0:misc/py-progressbar \
		${PYTHON_PKGNAMEPREFIX}rpyc>0:devel/py-RPyC \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}cherrypy>0:www/py-cherrypy \
		${PYTHON_PKGNAMEPREFIX}requests>=1.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.0:devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}tvrage>0:devel/py-tvrage \
		${PYTHON_PKGNAMEPREFIX}tmdb3>0:www/py-tmdb3 \
		${PYTHON_PKGNAMEPREFIX}apscheduler>0:devel/py-apscheduler \
		${PYTHON_PKGNAMEPREFIX}guessit>=0.9.3:multimedia/py-guessit \
		${PYTHON_PKGNAMEPREFIX}path.py>=6.2:devel/py-path.py
TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES=		python:2
USE_PYTHON=	autoplist distutils

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>

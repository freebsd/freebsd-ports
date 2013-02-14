# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flexget
PORTVERSION=	1.0.3273
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	http://download.flexget.com/archive/ \
		http://download.flexget.com/ \
		http://ompldr.org/vaGI2Mw/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FlexGet-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Program to automate downloading from different sources

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0.11:${PORTSDIR}/devel/py-nose
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.7:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0.11:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}pygooglechart>=0:${PORTSDIR}/graphics/py-pygooglechart \
		${PYTHON_PKGNAMEPREFIX}progressbar>=0:${PORTSDIR}/misc/py-progressbar \
		${PYTHON_PKGNAMEPREFIX}pynzb>=0:${PORTSDIR}/news/py-pynzb \
		${PYTHON_PKGNAMEPREFIX}feedparser>=5.1.2:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}rss2gen>=0:${PORTSDIR}/textproc/py-rss2gen \
		${PYTHON_SITELIBDIR}/BeautifulSoup.py:${PORTSDIR}/www/py-beautifulsoup32 \
		${PYTHON_SITELIBDIR}/bs4/__init__.py:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=3.2.0:${PORTSDIR}/www/py-cherrypy \
		${PYTHON_PKGNAMEPREFIX}Flask>=0:${PORTSDIR}/www/py-flask \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.11:${PORTSDIR}/www/py-html5lib \
		${PYTHON_PKGNAMEPREFIX}requests>=0.14:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}nose>=0.11:${PORTSDIR}/devel/py-nose

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	FlexGet
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}
PYDISTUTILS_NOEGGINFO=	yes

PLIST_SUB=	PYDISTUTILS_EGGINFO=${PYDISTUTILS_EGGINFO}

post-extract:
	@${CHMOD} -R o+r ${WRKSRC}

.include <bsd.port.mk>

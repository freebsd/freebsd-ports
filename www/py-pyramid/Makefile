# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyramid
PORTVERSION=	1.5.7
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Small, fast, web development framework by the Pylons community

LICENSE=	REPOZE
LICENSE_NAME=	Repoze License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}repoze.lru>=0.4:${PORTSDIR}/devel/py-repoze.lru \
		${PYTHON_PKGNAMEPREFIX}translationstring>=0.4:${PORTSDIR}/textproc/py-translationstring \
		${PYTHON_PKGNAMEPREFIX}venusian>=1.0:${PORTSDIR}/devel/py-venusian \
		${PYTHON_PKGNAMEPREFIX}webob>=1.3.1:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>=3.5.0:${PORTSDIR}/devel/py-zope.deprecation \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.8.0:${PORTSDIR}/devel/py-zope.interface
RUN_DEPENDS:=	${BUILD_DEPENDS}

#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}WebTest>=1.1:${PORTSDIR}/www/py-WebTest \
#		${PYTHON_PKGNAMEPREFIX}zope.component>=3.6.0:${PORTSDIR}/devel/py-zope.component

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

PORTNAME=	zope.tal
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	textproc python zope
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Template Application Language (TAL)
WWW=		https://pypi.org/project/zope.tal/

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

# Created by: D'Arcy Cain <darcy@druid.net>
# $FreeBSD$

PORTNAME=	weasyprint
PORTVERSION=	47
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WeasyPrint-${PORTVERSION}

MAINTAINER=	darcy@druid.net
COMMENT=	Converts HTML/CSS documents to PDF

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0.1:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=0.1:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999999999:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfrw>=0.4:textproc/py-pdfrw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyphen>=0.8:textproc/py-pyphen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss>=0.4:textproc/py-tinycss@${PY_FLAVOR}

USES=		gnome python:3.6+
USE_PYTHON=	distutils autoplist
USE_GNOME=	pango

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	Lektor
PORTVERSION=	3.3.10
CATEGORIES=	www devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Static content management system written in Python
WWW=		https://www.getlektor.com/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ExifRead>=0:graphics/py-exifread@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=6.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>=0:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enum-compat>=0:devel/py-enum-compat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filetype>=1.0.7:devel/py-filetype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inifile>=0:devel/py-inifile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune0>=0.7.0<2:textproc/py-mistune0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathlib2>=0:devel/py-pathlib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slugify>=0:textproc/py-python-slugify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=0:devel/py-watchdog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug<=3:www/py-werkzeug@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} 's/%%PORTVERSION%%/${PORTVERSION}/g' ${WRKSRC}/setup.py

.include <bsd.port.mk>

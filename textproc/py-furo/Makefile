# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	furo
PORTVERSION=	2022.1.2
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP \
		LOCAL/sunpoet:static
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-static${EXTRACT_SUFX}:static

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Clean customizable Sphinx documentation theme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.7<3:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=4.0,1<5,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

post-install:
	cd ${WRKDIR}/static/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/furo/theme/furo/static/

.include <bsd.port.mk>

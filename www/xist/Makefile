# Created by: ijliao
# $FreeBSD$

PORTNAME=	xist
PORTVERSION=	5.32
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://ftp.livinglogic.de/xist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ll-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	XML-based extensible HTML generator

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssutils>=1.0,1:www/py-cssutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.4:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.6:graphics/py-pillow@${PY_FLAVOR}

USES=		python:3.6+ tar:bzip2
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ll/*.so ${STAGEDIR}${PYTHON_SITELIBDIR}/ll/xist/*.so

.include <bsd.port.mk>

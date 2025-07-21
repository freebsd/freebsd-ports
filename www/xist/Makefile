PORTNAME=	xist
PORTVERSION=	5.34
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		http://ftp.livinglogic.de/xist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ll-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	XML-based extensible HTML generator
WWW=		http://www.livinglogic.de/Python/xist/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssutils>=1.0,1:www/py-cssutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=3.4:devel/py-lxml5@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		python tar:bzip2
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ll/*.so ${STAGEDIR}${PYTHON_SITELIBDIR}/ll/xist/*.so

.include <bsd.port.mk>

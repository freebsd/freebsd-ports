PORTNAME=	readability-lxml
DISTVERSION=	0.8.4.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S|-|_|}-${DISTVERSION}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Fast HTML to text parser (article readability tool)
WWW=		https://github.com/buriy/python-readability

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>0:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timeout-decorator>0:devel/py-timeout-decorator@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CCHARDET

CCHARDET_DESC=			Use cchardet instead of chardet
CCHARDET_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}cchardet>0:textproc/py-cchardet@${PY_FLAVOR}
CCHARDET_RUN_DEPENDS_OFF=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR}

.include <bsd.port.mk>

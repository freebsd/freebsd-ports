PORTNAME=	feedgen
DISTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Feed Generator for ATOM, RSS and Podcasts
WWW=		https://lkiesow.github.io/python-feedgen

LICENSE=	BSD2CLAUSE LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/license.bsd
LICENSE_FILE_LGPL3+ =	${WRKSRC}/license.lgpl

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

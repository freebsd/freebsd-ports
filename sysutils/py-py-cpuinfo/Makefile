PORTNAME=	py-cpuinfo
DISTVERSION=	9.0.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Module for getting CPU info with pure Python
WWW=		https://github.com/workhorsy/py-cpuinfo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=	LSCPU
OPTIONS_DEFAULT=	LSCPU
LSCPU_DESC=	Use sysutils/lscpu as a data source
LSCPU_RUN_DEPENDS=	lscpu:sysutils/lscpu

.include <bsd.port.mk>

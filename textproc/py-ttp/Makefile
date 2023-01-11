PORTNAME=	ttp
PORTVERSION=	0.9.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Template Text Parser
WWW=		https://github.com/dmulyalin/ttp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		dos2unix python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/ttp/utils/load_python_exec_py2.py

.include <bsd.port.mk>

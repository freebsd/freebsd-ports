# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ttp
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Template Text Parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		dos2unix python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/ttp/utils/load_python_exec_py2.py

.include <bsd.port.mk>

# Created by: Ben Woods <woodsb02@FreeBSD.org>

PORTNAME=	distro
PORTVERSION=	1.7.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Linux OS platform information API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	query_local_distro.py

.include <bsd.port.mk>

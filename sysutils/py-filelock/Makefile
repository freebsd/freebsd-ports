PORTNAME=	filelock
DISTVERSION=	3.4.2
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Platform independent file lock

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch: # workaround for https://github.com/tox-dev/py-filelock/issues/133
	@${REINPLACE_CMD} -e 's|author = Benedikt Schmitt|version = ${PORTVERSION}|' ${WRKSRC}/setup.cfg

.include <bsd.port.mk>

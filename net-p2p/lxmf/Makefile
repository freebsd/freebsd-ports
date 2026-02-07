PORTNAME=	lxmf
DISTVERSION=	0.8.0
CATEGORIES=	net-p2p
MASTER_SITES=	PYPI

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Lightweight Extensible Message Format for Reticulum
WWW=		https://github.com/markqvist/nomadnet

LICENSE=	UNKNOWN
LICENSE_NAME=	Reticulum License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	reticulum>0:net-p2p/reticulum

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

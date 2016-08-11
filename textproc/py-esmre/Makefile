# $FreeBSD$

PORTNAME=	esmre
PORTVERSION=	0.3.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	Regular expression accelerator in Python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib -name "*.so" -and -exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>

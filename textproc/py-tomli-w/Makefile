# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	tomli-w
PORTVERSION=	0.4.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tomli_w-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lil' TOML writer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>

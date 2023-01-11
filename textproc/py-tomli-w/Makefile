PORTNAME=	tomli-w
PORTVERSION=	1.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tomli_w-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lil' TOML writer
WWW=		https://github.com/hukkin/tomli-w

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.mk>

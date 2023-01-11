PORTNAME=	youseedee
PORTVERSION=	0.3.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interface to the Unicode Character Database
WWW=		https://github.com/simoncozens/youseedee

LICENSE=	MIT

RUN_DEPENDS=	UCD>=0:textproc/UCD

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%UCDDIR%%|${LOCALBASE}/share/unicode/ucd|' ${WRKSRC}/lib/youseedee/__init__.py

.include <bsd.port.mk>

# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	httptools
PORTVERSION=	0.2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of framework independent HTTP protocol utils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhttp_parser.so:www/http-parser

USES=		localbase python:3.5+
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@${RM} -r ${WRKSRC}/vendor/http-parser/

.include <bsd.port.mk>

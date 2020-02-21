# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httptools
PORTVERSION=	0.1.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of framework independent HTTP protocol utils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhttp_parser.so:www/http-parser

USES=		localbase python:3.5+
USE_PYTHON=	autoplist distutils

post-patch:
	@${RM} -r ${WRKSRC}/vendor/

.include <bsd.port.mk>

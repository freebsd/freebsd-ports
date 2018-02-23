# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	http-parser
PORTVERSION=	0.8.3
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	HTTP request/response parser for python in C

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

post-build:
	@${STRIP_CMD} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/http_parser/parser.so

.include <bsd.port.mk>

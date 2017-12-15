# Created by: ijliao
# $FreeBSD$

PORTNAME=	cryptkit
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/_${PORTNAME}/Complete%20Kit
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cryptographic Toolkit for Python

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/*.so

.include <bsd.port.mk>

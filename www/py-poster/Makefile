# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	poster
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://atlee.ca/software/poster/dist/${PORTVERSION}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Streaming HTTP uploads and multipart/form-data encoding

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>

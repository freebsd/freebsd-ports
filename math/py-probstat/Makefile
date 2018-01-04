# Created by: ijliao
# $FreeBSD$

PORTNAME=	probstat
PORTVERSION=	0.912
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Probability And Statistics Utils for Python

USES=		python:2.7 tar:tgz
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/probstat.so

.include <bsd.port.mk>

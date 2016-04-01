# $FreeBSD$

PORTNAME=	snowballstemmer
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Snowball stemming library collection for Python

LICENSE=	BSD2CLAUSE

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	PYSTEMMER
OPTIONS_DEFAULT=PYSTEMMER
PYSTEMMER_DESC=	Use PyStemmer to accelerate

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYSTEMMER}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pystemmer>0:textproc/py-pystemmer
.endif

.include <bsd.port.mk>

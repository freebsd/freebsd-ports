# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygments
DISTVERSION=	2.7.1
PORTREVISION=	0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pygments-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Syntax highlighter written in Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

CONFLICTS_INSTALL=	py??-pygments-25

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == ${PYTHON_DEFAULT}
CONFLICTS_INSTALL=	paraview
.endif

.include <bsd.port.post.mk>

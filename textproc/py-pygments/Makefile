# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygments
PORTVERSION=	2.3.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pygments-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Syntax highlighter written in Python

LICENSE=	BSD2CLAUSE

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == ${PYTHON_DEFAULT}
CONFLICTS_INSTALL=	paraview
.endif

.include <bsd.port.post.mk>

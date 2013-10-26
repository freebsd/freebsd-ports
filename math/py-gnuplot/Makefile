# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnuplot
PORTVERSION=	1.8
PORTREVISION=	5
CATEGORIES=	math python
MASTER_SITES=	SF/${PORTNAME}-py/Gnuplot-py/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gnuplot-py-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to gnuplot plotting program

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		${PYNUMPY}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	gnuplot-py

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>

# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dot2tex
PORTVERSION=	2.8.7
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	A Graphviz to LaTeX converter

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		dot:${PORTSDIR}/graphics/graphviz

USE_PYDISTUTILS=yes
USE_PYTHON=	yes
# The .tar.gz sucks!
USES=		zip

NO_STAGE=	yes
.include <bsd.port.mk>

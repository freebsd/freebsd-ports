# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dot2tex
PORTVERSION=	2.8.7
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Graphviz to LaTeX converter

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		dot:${PORTSDIR}/graphics/graphviz

# The .tar.gz sucks!
USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

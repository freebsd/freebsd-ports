# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dot2tex
PORTVERSION=	2.8.7
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Graphviz to LaTeX converter

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing \
		dot:graphics/graphviz

# The .tar.gz sucks!
USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

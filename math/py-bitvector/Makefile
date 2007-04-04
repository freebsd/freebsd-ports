# New ports collection makefile for:	py-bitvector
# Date created:		2006-12-27
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	bitvector
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://cobweb.ecn.purdue.edu/~kak/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	BitVector-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A pure-Python memory-efficient packed representation for bit arrays

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/BitVector.py \
		%%PYTHON_SITELIBDIR%%/BitVector.pyc \
		%%PYTHON_SITELIBDIR%%/BitVector.pyo

.include <bsd.port.mk>

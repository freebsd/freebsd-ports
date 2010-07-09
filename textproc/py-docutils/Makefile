# ex:ts=8
# Ports collection makefile for:	py-docutils
# Date created:			Sep 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	docutils
PORTVERSION=	0.7
CATEGORIES=	textproc python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python Documentation Utilities

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

BINS=		bin/rst2xml.py bin/rst2s5.py bin/rst2pseudoxml.py \
		bin/rst2newlatex.py bin/rst2latex.py bin/rst2html.py

post-install:
.for i in ${BINS}
	${MV} -f ${PREFIX}/${i} ${PREFIX}/${i:S/.py//g}
.endfor

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	py-docutils
# Date created:			Sep 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	docutils
PORTVERSION=	0.3.9
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Documentation Utilities

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${MV} -f ${PREFIX}/bin/rst2html.py ${PREFIX}/bin/rst2html
	@${MV} -f ${PREFIX}/bin/rst2latex.py ${PREFIX}/bin/rst2latex

.include <bsd.port.mk>

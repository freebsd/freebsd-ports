# ex:ts=8
# Ports collection makefile for:	py-cssutils
# Date created:			Aug 26, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cssutils
PORTVERSION=	0.53
CATEGORIES=	www python
MASTER_SITES=	http://cthedot.de/cssutils/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CSS Cascading Style Sheets library for Python

RUN_DEPENDS=	${PYXML}

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/${PORTNAME} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>

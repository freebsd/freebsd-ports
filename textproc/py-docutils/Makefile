# ex:ts=8
# Ports collection makefile for:	py-docutils
# Date created:			Sep 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	docutils
PORTVERSION=	0.3.5
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Documentation Utilities

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	bin/rst2html bin/rst2latex

post-install:
	@${MV} -f ${PREFIX}/bin/rst2html.py ${PREFIX}/bin/rst2html
	@${MV} -f ${PREFIX}/bin/rst2latex.py ${PREFIX}/bin/rst2latex
	@${FIND} ${PYTHON_SITELIBDIR}/docutils ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/docutils -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>

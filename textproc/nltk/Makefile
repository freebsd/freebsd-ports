# ex:ts=8
# Ports collection makefile for:	nltk
# Date created:				Oct 30, 2003
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	nltk
PORTVERSION=	1.4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clsung@dragon2.net
COMMENT=	Natural language toolkit written in python

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Coredump during build on alpha 4.x"
.endif

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/nltk ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/nltk -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>

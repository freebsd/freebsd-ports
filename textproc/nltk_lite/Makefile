# ex:ts=8
# Ports collection makefile for:	nltk_lite
# Date created:				Sat Nov 26 11:13:22 CST 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	nltk_lite
PORTVERSION=	0.6.4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:C/_.*//}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Lightweight Natural language toolkit written in python

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.pre.mk>

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/nltk_lite ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/nltk_lite -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>

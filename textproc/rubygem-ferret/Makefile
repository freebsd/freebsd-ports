# New ports collection makefile for:	ferret
# Date created:		2006-08-10
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ferret
PORTVERSION=	0.11.6
CATEGORIES=	textproc rubygems
MASTER_SITES=	RF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ferret is a ruby port of Lucene

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes

post-install:
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>

# New ports collection makefile for:	ferret
# Date created:		2006-08-10
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ferret
PORTVERSION=	0.11.4
CATEGORIES=	textproc rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ferret is a ruby port of Lucene

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake

USE_RUBY=	yes

post-install:
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>

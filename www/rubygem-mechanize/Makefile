# Ports collection makefile for:	rubygem-mechanize
# Date created:				5 Feb 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mechanize
PORTVERSION=	0.7.0
CATEGORIES=	www rubygems
MASTER_SITES=	RF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	WWW::Mechanize, a handy web browsing ruby object

BUILD_DEPENDS=	rubygem-hpricot>=0:${PORTSDIR}/www/rubygem-hpricot \
		rubygem-hoe>=1.2.2:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes

post-install:
	@${ECHO} ${GEM_CACHE} > ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm ${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>

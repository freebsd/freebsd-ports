# Ports collection makefile for:	rubygem-passenger
# Date created:				Dec 18, 2008
# Whom:					Jacob Atzen <jatzen@gmail.com>
#
# $FreeBSD$

PORTNAME=	passenger
PORTVERSION=	2.1.3
CATEGORIES=	www rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	gems

MAINTAINER=	jatzen@gmail.com
COMMENT=	Apache module for running Ruby on Rails and Rack applications

BUILD_DEPENDS=	rubygem-fastthread>=1.0.1:${PORTSDIR}/devel/rubygem-fastthread \
		rubygem-rack>=0.1.0:${PORTSDIR}/www/rubygem-rack

SUB_LIST+=	GEM_LIB_DIR=${GEM_LIB_DIR} RUBY=${RUBY}
SUB_FILES=	pkg-message

USE_APACHE=	2.2+
USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes

post-install:
	(${PREFIX}/bin/passenger-install-apache2-module --auto )
	@${CAT}	${PKGMESSAGE}
	@${ECHO} bin/passenger-config >	${TMPPLIST}
	@${ECHO} bin/passenger-install-apache2-module >> ${TMPPLIST}
	@${ECHO} bin/passenger-make-enterprisey >> ${TMPPLIST}
	@${ECHO} bin/passenger-memory-stats >> ${TMPPLIST}
	@${ECHO} bin/passenger-spawn-server >> ${TMPPLIST}
	@${ECHO} bin/passenger-status >> ${TMPPLIST}
	@${ECHO} bin/passenger-stress-test >> ${TMPPLIST}
	@${ECHO} ${GEM_CACHE} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm ${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>

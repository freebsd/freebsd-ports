# New ports collection makefile for:	instiki
# Date created:				4 January 2005
# Whom:					Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	instiki
PORTVERSION=	0.12.0
CATEGORIES=	www ruby
MASTER_SITES=	RF
DISTNAME=	${PORTNAME}-0.12.0
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Easy to set up wiki clone implemented in ruby

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake


USE_RUBY=	yes
USE_RUBY_FEATURES=	1.8
USE_LDCONFIG=	yes

INSTIKIPORT?=	2500

OPTIONS=	PORT_BLUECLOTH	"Use BlueCloth gem from ports" On

.include <bsd.port.pre.mk>

USE_RC_SUBR=	${PORTNAME}
SUB_LIST=	INSTIKIPORT=${INSTIKIPORT} \
		RUBY_WITH_SUFFIX=${RUBY_WITH_SUFFIX}
SUB_FILES+=	pkg-deinstall pkg-message
RUBY_SHEBANG_FILES=instiki

.if defined(WITH_PORT_BLUECLOTH)
# can't include this because it redefines do-install.
# .include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
# For now, copy and paste the definition of SPEC_DIR from the above
REV=		1.8
GEMS_BASE_DIR=	lib/ruby/gems/${REV}
SPEC_DIR=	${GEMS_BASE_DIR}/specifications
BUILD_DEPENDS+=	${LOCALBASE}/${SPEC_DIR}/BlueCloth-1.0.0.gemspec:${PORTSDIR}/www/rubygem-bluecloth
EXTRA_PATCHES+=	${FILESDIR}/bluecloth-patch-lib-chunks-engines-rb
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} " ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "				WARNING!"
	@${ECHO_MSG} "If you are updating from a previous version, Hit ^c now"
	@${ECHO_MSG} "and read /usr/ports/UPDATING!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !"

post-extract:	
	@find -d ${WRKSRC} -type d -name .svn -exec rm -rf {} \;

post-patch:
	${RM} ${WRKSRC}/lib/chunks/engines.rb.orig

do-build:
	( cd ${WRKSRC}/db/ && \
	  rake environment RAILS_ENV=production db:migrate )

do-install:
	@${FIND} -E ${WRKSRC} -type f -iregex ".*\._.+" -exec ${RM} "{}" \;
	@${INSTALL} -d ${DATADIR}
	@${CP} -pR ${WRKSRC}/ ${DATADIR}
	@${CP} -n ${DATADIR}/db/production.db.sqlite3 ${DATADIR}/db/default.db.sqlite3

post-install:
	@${CAT} ${PKGMESSAGE}


.include <bsd.port.post.mk>

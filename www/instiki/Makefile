# New ports collection makefile for:	instiki
# Date created:				4 January 2005
# Whom:					Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	instiki
PORTVERSION=	0.11.0
PORTREVISION=	3
CATEGORIES=	www ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.11.pl1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to set up wiki clone implemented in ruby

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake

USE_RUBY=	yes
USE_RUBY_FEATURES=	1.8

INSTIKIDIR?=	instiki
INSTIKIPORT?=	2500

USE_RC_SUBR=	${PORTNAME}
PLIST_SUB=	INSTIKIDIR=${INSTIKIDIR}/
SUB_LIST+=	INSTIKIDIR=${INSTIKIDIR} \
		INSTIKIPORT=${INSTIKIPORT} \
		RUBY_WITH_SUFFIX=${RUBY_WITH_SUFFIX}
SUB_FILES+=	pkg-deinstall
RUBY_SHEBANG_FILES=instiki

OPTIONS=	PORT_BLUECLOTH	"Use BlueCloth gem from ports" On

do-build:
	( cd ${WRKSRC}/db/ && \
	  rake environment RAILS_ENV=production migrate )

do-install:
	@${FIND} -E ${WRKSRC} -type f -iregex ".*\._.+" -exec ${RM} "{}" \;
	${CP} -pR ${WRKSRC}/ ${PREFIX}/${INSTIKIDIR}
	${CP} ${PREFIX}/${INSTIKIDIR}/db/production.db.sqlite3 \
		${PREFIX}/${INSTIKIDIR}/db/default.db.sqlite3
	${CHMOD} +x ${PREFIX}/${INSTIKIDIR}/instiki

.include <bsd.port.pre.mk>

.if defined(WITH_PORT_BLUECLOTH)

# can't include this because it redefines do-install.
# .include "${PORTSDIR}/devel/ruby-gems/Makefile.common"

# For now, copy and paste the definition of SPEC_DIR from the above
REV=		1.8
GEMS_BASE_DIR=	lib/ruby/gems/${REV}
SPEC_DIR=	${GEMS_BASE_DIR}/specifications

RUN_DEPENDS+=	${LOCALBASE}/${SPEC_DIR}/BlueCloth-1.0.0.gemspec:${PORTSDIR}/www/rubygem-bluecloth

EXTRA_PATCHES+=	${FILESDIR}/bluecloth-patch-lib-chunks-engines-rb

post-patch:
	${RM} ${WRKSRC}/lib/chunks/engines.rb.orig

.endif

.include <bsd.port.post.mk>

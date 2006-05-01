# New ports collection makefile for:	instiki
# Date created:				4 January 2005
# Whom:					Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	instiki
PORTVERSION=	0.11.0
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/9296/
EXTRACT_SUFX=	.tgz

MAINTAINER=	arsptr@optusnet.com.au
COMMENT=	Easy to set up wiki clone implemented in ruby

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/sqlite3_api.so:${PORTSDIR}/databases/ruby-sqlite3
BUILD_DEPENDS+=	${RUN_DEPENDS} rake:${PORTSDIR}/devel/rubygem-rake
PATCH_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes
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

post-patch:
	( cd ${WRKSRC}/db/ && \
	  rake environment RAILS_ENV=production migrate )

do-install:
	${CP} -pR ${WRKSRC}/ ${PREFIX}/${INSTIKIDIR}
	${CP} ${PREFIX}/${INSTIKIDIR}/db/production.db.sqlite3 ${PREFIX}/${INSTIKIDIR}/db/default.db.sqlite3
	${CHMOD} +x ${PREFIX}/${INSTIKIDIR}/instiki

.include <bsd.port.mk>

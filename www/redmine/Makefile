# New ports collection makefile for:	redmine
# Date created:		2009-02-24
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	redmine
PORTVERSION=	1.3.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A flexible project management web application

RUN_DEPENDS=	rackup:${PORTSDIR}/www/rubygem-rack \
		rubygem-rubytree>=0:${PORTSDIR}/devel/rubygem-rubytree \
		rubygem-i18n>=0.4.2:${PORTSDIR}/devel/rubygem-i18n

.if defined(RUBY_VER) && ${RUBY_VER} != "1.8"
IGNORE=		requires ruby1.8, but you have RUBY_VER set to 1.9
.else
RUBY_VER=	1.8
.endif
USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RAKE=	yes
NO_BUILD=	yes
SUB_LIST+=	RUBY_NAME=${RUBY_NAME}

BROKEN=		Does not work with RubyGems 1.8

OPTIONS=	MYSQL "Enable MySQL support" on \
		POSTGRESQL "Enable PostgreSQL support" off \
		RMAGIC "Enable Gantt charts support" on \
		THIN "Use Thin WEB server" on \
		PASSENGER "Use Apache/Nginx WEB server" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/mysql.so:${PORTSDIR}/databases/ruby-mysql
.endif

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
.endif

.if defined(WITH_RMAGIC)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/RMagick2.so:${PORTSDIR}/graphics/ruby-rmagick
.endif

.if defined(WITH_THIN)
USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
RUN_DEPENDS+=	thin:${PORTSDIR}/www/rubygem-thin
USE_RC_SUBR=	redmine
SUB_LIST+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
.endif

.if defined(WITH_PASSENGER)
RUN_DEPENDS+=	passenger-config:${PORTSDIR}/www/rubygem-passenger
.endif

.if !defined(WITH_THIN) && !defined(WITH_PASSENGER)
IGNORE=		either Thin or Apache/Nginx WEB server option required. \
		Please 'make config' again.
.endif

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${WWWDIR} "! ( -name *\.orig -o -name *\.bak )")

	${MKDIR} ${WWWDIR}/public/plugin_assets
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

	${FIND} ${WWWDIR}/script -type f -exec ${CHMOD} 755 {} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

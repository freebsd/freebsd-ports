# New ports collection makefile for:	redmine
# Date created:		2009-02-24
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	redmine
PORTVERSION=	0.9.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A flexible project management web application

RUN_DEPENDS=	rackup:${PORTSDIR}/www/rubygem-rack

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RAKE=	yes
NO_BUILD=	yes
SUB_LIST+=	RUBY_NAME=${RUBY_NAME}

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
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/pg.so:${PORTSDIR}/databases/ruby-pg
.endif

.if defined(WITH_RMAGIC)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/RMagick2.so:${PORTSDIR}/graphics/ruby-rmagick
.endif

.if defined(WITH_THIN)
RUN_DEPENDS+=	thin:${PORTSDIR}/www/rubygem-thin
USE_RC_SUBR=	redmine
.endif

.if defined(WITH_PASSENGER)
RUN_DEPENDS+=	passenger-config:${PORTSDIR}/www/rubygem-passenger
.endif

.if !defined(WITH_THIN) && !defined(WITH_PASSENGER)
IGNORE=		Either Thin or Apache/Nginx WEB server option required. \
		Please 'make config' again.
.endif

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${WWWDIR} "! -name *.orig")

	${MKDIR} ${WWWDIR}/public/plugin_assets
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

	${FIND} ${WWWDIR}/script -type f -exec ${CHMOD} 755 {} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

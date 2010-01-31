# New ports collection makefile for:	redmine
# Date created:		2009-02-24
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	redmine
PORTVERSION=	0.9.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	decke@bluelife.at
COMMENT=	A flexible project management web application

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RAKE=	yes
NO_BUILD=	yes

OPTIONS=	MYSQL	"Enable MySQL Support" on \
		POSTGRESQL "Enable PostgreSQL Support" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/mysql.so:${PORTSDIR}/databases/ruby-mysql
.endif

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/pg.so:${PORTSDIR}/databases/ruby-pg
.endif

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${WWWDIR} "! -name *.orig")

	${MKDIR} ${WWWDIR}/public/plugin_assets
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

.for f in files log tmp public/plugin_assets
	${CHMOD} -R 755 ${WWWDIR}/${f}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

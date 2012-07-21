# New ports collection makefile for:	redmine
# Date created:		2009-02-24
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	redmine
PORTVERSION=	1.3.1
PORTREVISION=	1
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

OPTIONS_DEFINE=	MYSQL POSTGRESQL RMAGIC WWWSERVER
OPTIONS_DEFAULT=MYSQL            RMAGIC WWWSERVER THIN
OPTIONS_SINGLE=	WWWSERVER
OPTIONS_SINGLE_WWWSERVER=	THIN PASSENGER
POSTGRESQL_DESC=Enable PostgreSQL support
RMAGIC_DESC=	Enable Gantt charts support
THIN_DESC=	Use Thin WEB server
PASSENGER_DESC=	Use Apache/Nginx WEB server
NO_OPTIONS_SORT=yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/mysql.so:${PORTSDIR}/databases/ruby-mysql
.endif

.if ${PORT_OPTIONS:MPOSTGRESQL}
RUN_DEPENDS+=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
.endif

.if ${PORT_OPTIONS:MRMAGIC}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/RMagick2.so:${PORTSDIR}/graphics/ruby-rmagick
.endif

.if ${PORT_OPTIONS:MTHIN}
USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
RUN_DEPENDS+=	thin:${PORTSDIR}/www/rubygem-thin
USE_RC_SUBR=	redmine
SUB_LIST+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
.endif

.if ${PORT_OPTIONS:MPASSENGER}
RUN_DEPENDS+=	passenger-config:${PORTSDIR}/www/rubygem-passenger
.endif

post-extract:
	${MV} ${WRKSRC}/config/settings.yml ${WRKSRC}/config/settings.yml-dist

pre-install:
	${MKDIR} ${WRKSRC}/public/plugin_assets

do-install:
	${MKDIR} ${WWWDIR}
	cd ${WRKSRC} && \
	${COPYTREE_SHARE} "*" ${WWWDIR} "! ( -name *\.orig -o -name *\.bak )"
	${FIND} ${WRKSRC}/script -type f -print | ${XARGS} ${CHMOD} 755

post-install:
	if ! [ -r ${WWWDIR}/config/settings.yml ]; then			\
		${INSTALL_DATA} ${WWWDIR}/config/settings.yml-dist	\
			${WWWDIR}/config/settings.yml;			\
	fi
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		shared_calendars
PORTVERSION=		2.0.1
PORTREVISION=	1
CATEGORIES=		mail www
MASTER_SITES=		http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=		squirrelmail-
PKGNAMESUFFIX=		-plugin
DISTNAME=		${PORTNAME}-${PORTVERSION}-1.4.0
DIST_SUBDIR=		squirrelmail

MAINTAINER=		ports@FreeBSD.org
COMMENT=		iCal-compliant calendaring for SquirrelMail

RUN_DEPENDS=		${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail \
			${SQUIRRELDIR}/plugins/compatibility:${PORTSDIR}/mail/squirrelmail-compatibility-plugin

SQUIRREL_PLUGIN_NAME=	${PORTNAME}

.ifdef SQUIRRELDIR
PLIST_SUB+=		SQUIRRELDIR=${SQUIRRELDIR}
SUB_LIST+=		"SQUIRRELDIR=${SQUIRRELDIR}"
.else
.	ifndef WITHOUT_WWWDIR
SQUIRRELDIR=		${PREFIX}/www/squirrelmail
PLIST_SUB+=		SQUIRRELDIR=www/squirrelmail
SUB_LIST+=		"SQUIRRELDIR=www/squirrelmail"
.	else
SQUIRRELDIR=		${PREFIX}/squirrelmail
PLIST_SUB+=		SQUIRRELDIR=squirrelmail
SUB_LIST+=		"SQUIRRELDIR=squirrelmail"
.	endif
.endif

SUB_FILES=		pkg-message

USES=			perl5
NO_BUILD=		yes
NO_WRKSUBDIR=		yes
USE_PERL5=		build
USE_PHP=		yes
WANT_PHP_WEB=		yes

OPTIONS_DEFINE=	SQL
SQL_DESC=	use SQL backend

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQL}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/calendar_sql_backend:${PORTSDIR}/mail/squirrelmail-calendar_sql_backend-plugin
.else
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/calendar_file_backend:${PORTSDIR}/mail/squirrelmail-calendar_file_backend-plugin
.endif

pre-everything::
	@${ECHO} ""
.ifndef WITHOUT_ACTIVATE
	@${ECHO} "Activating plug-in in SquirrelMail after installation."
	@${ECHO} "If you don't want to automatically activate the plug-in set"
	@${ECHO} "WITHOUT_ACTIVATE=yes"
.else
	@${ECHO} "NOT Activating plug-in in SquirrelMail after installation."
	@${ECHO} "If you want to automatically activate the plug-in unset"
	@${ECHO} "WITHOUT_ACTIVATE"
.endif
	@${ECHO} ""

do-install:
	${CP} -rp ${WRKSRC}/calendar ${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME}

post-install:
.ifndef WITHOUT_ACTIVATE
.if exists( ${SQUIRRELDIR}/config/config.php )
	@${ECHO} "Activating plug-in in SquirrelMail"
	${SQUIRRELDIR}/config/conf.pl --install-plugin ${SQUIRREL_PLUGIN_NAME}
.endif
.else
	@${ECHO} "To activate the plug-in in SquirrelMail use"
	@${ECHO} "${SQUIRRELDIR}/config/conf.pl --install-plugin ${SQUIRREL_PLUGIN_NAME}"
.endif
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

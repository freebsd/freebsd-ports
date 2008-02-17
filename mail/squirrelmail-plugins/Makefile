# New ports collection makefile for:		squirrelmail-plugins
# Date created:		02 Jan 2008
# Whom:		Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$

PORTNAME=		squirrelmail-plugins
PORTVERSION=		1.0
PORTREVISION=		1
CATEGORIES=		mail www
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		gerrit.beine@gmx.de
COMMENT=		A "meta-port" to install SquirrelMail plugins

NO_BUILD=	yes

.ifdef SQUIRRELDIR
PLIST_SUB+=	SQUIRRELDIR=${SQUIRRELDIR}
SUB_LIST+=	"SQUIRRELDIR=${SQUIRRELDIR}"
.else
.ifndef WITHOUT_WWWDIR
SQUIRRELDIR=	${PREFIX}/www/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=www/squirrelmail
SUB_LIST+=	"SQUIRRELDIR=www/squirrelmail"
.else
SQUIRRELDIR=	${PREFIX}/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=squirrelmail
SUB_LIST+=	"SQUIRRELDIR=squirrelmail"
.endif
.endif

OPTIONS=	SIEVE	"Sieve Mail Filters plugin" off \
		CALENDR	"Shared Calendars plugin" off \
		LDAPPW	"Change LDAP passwords plugin" off \
		SQLPW	"Change *SQL passwords plugin" off \
		MAILFT	"E-mail footer plugin" off \
		LGAUTH	"HTTP-auth based login plugin" off \
		LGNOTES	"Notes on login screen plugin" off \
		MLOGIN	"Multilogin plugin" off \
		NOTES	"Notes plugin" off \
		NOTIFY	"New mail notify plugin" off \
		PW4GET	"Password forget plugin" off \
		PUPDATE	"Plugin update check plugin" off \
		QMADMIN	"Qmailadmin login plugin" off \
		QUOTA	"Quota usage plugin" off \
		SASQL	"SpamAssassin SQL plugin" off \
		BUTTONS "Custom (spam/ham/etc.) buttons" off \
		SLOGIN	"SSL login plugin" off \
		TIMEOUT	"User session timeout plugin" off \
		TMDA	"TMDA plugin" off \
		VLOGIN	"Multi-site-hosting capabilities plugin" off \
		WEBSRCH	"Web search engines plugin" off \
		WETTER	"Weather in Germany plugin" off
#		NEWUSER "New user wizard plugin" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SIEVE) || defined(WITH_SIEVE)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/avelsieve:${PORTSDIR}/mail/squirrelmail-avelsieve-plugin
.endif

.if !defined(WITHOUT_CALENDR) || defined(WITH_CALENDR)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/calendar:${PORTSDIR}/mail/squirrelmail-shared_calendars-plugin
.endif

.if !defined(WITHOUT_LDAPPW) || defined(WITH_LDAPPW)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/change_ldappass:${PORTSDIR}/mail/squirrelmail-change_ldappass-plugin
.endif

.if !defined(WITHOUT_SQLPW) || defined(WITH_SQLPW)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/change_sqlpass:${PORTSDIR}/mail/squirrelmail-change_sqlpass-plugin
.endif

.if !defined(WITHOUT_MAILFT) || defined(WITH_MAILFT)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/email_footer:${PORTSDIR}/mail/squirrelmail-email_footer-plugin
.endif

.if !defined(WITHOUT_LGAUTH) || defined(WITH_LGAUTH)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/login_auth:${PORTSDIR}/mail/squirrelmail-login_auth-plugin
.endif

.if !defined(WITHOUT_LGNOTES) || defined(WITH_LGNOTES)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/login_notes:${PORTSDIR}/mail/squirrelmail-login_notes-plugin
.endif

.if !defined(WITHOUT_MLOGIN) || defined(WITH_MLOGIN)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/multilogin:${PORTSDIR}/mail/squirrelmail-multilogin-plugin
.endif
# requires compatibility1 plugin - breaks other plugins
#.if !defined(WITHOUT_NEWUSER) || defined(WITH_NEWUSER)
#RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/newuser_wiz:${PORTSDIR}/mail/squirrelmail-newuser_wiz-plugin
#.endif

.if !defined(WITHOUT_NOTES) || defined(WITH_NOTES)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/notes:${PORTSDIR}/mail/squirrelmail-notes-plugin
.endif

.if !defined(WITHOUT_NOTIFY) || defined(WITH_NOTIFY)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/notify:${PORTSDIR}/mail/squirrelmail-notify-plugin
.endif

.if !defined(WITHOUT_PW4GET) || defined(WITH_PW4GET)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/password_forget:${PORTSDIR}/mail/squirrelmail-password_forget-plugin
.endif

.if !defined(WITHOUT_PUPDATE) || defined(WITH_PUPDATE)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/pupdate:${PORTSDIR}/mail/squirrelmail-pupdate-plugin
.endif

.if !defined(WITHOUT_QMADMIN) || defined(WITH_QMADMIN)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/qmailadmin_login:${PORTSDIR}/mail/squirrelmail-qmailadmin_login-plugin
.endif

.if !defined(WITHOUT_QUOTA) || defined(WITH_QUOTA)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/quota_usage:${PORTSDIR}/mail/squirrelmail-quota_usage-plugin
.endif

.if !defined(WITHOUT_SASQL) || defined(WITH_SASQL)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/sasql:${PORTSDIR}/mail/squirrelmail-sasql-plugin
.endif

.if !defined(WITHOUT_BUTTONS) || defined(WITH_BUTTONS)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/spam_buttons:${PORTSDIR}/mail/squirrelmail-spam-buttons-plugin
.endif

.if !defined(WITHOUT_SLOGIN) || defined(WITH_SLOGIN)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/secure_login:${PORTSDIR}/mail/squirrelmail-secure_login-plugin
.endif

.if !defined(WITHOUT_TIMEOUT) || defined(WITH_TIMEOUT)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/timeout_user:${PORTSDIR}/mail/squirrelmail-timeout_user-plugin
.endif

.if !defined(WITHOUT_TMDA) || defined(WITH_TMDA)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/tmdatools:${PORTSDIR}/mail/squirrelmail-tmda-plugin
.endif

.if !defined(WITHOUT_VLOGIN) || defined(WITH_VLOGIN)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/vlogin:${PORTSDIR}/mail/squirrelmail-vlogin-plugin
.endif

.if !defined(WITHOUT_WEBSRCH) || defined(WITH_WEBSRCH)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/web_search:${PORTSDIR}/mail/squirrelmail-websearch-plugin
.endif

.if !defined(WITHOUT_WETTER) || defined(WITH_WETTER)
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/wetteronline:${PORTSDIR}/mail/squirrelmail-wetteronline-plugin
.endif

do-install: build
	@${DO_NADA}

.include <bsd.port.post.mk>

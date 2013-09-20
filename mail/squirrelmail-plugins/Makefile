# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		squirrelmail-plugins
PORTVERSION=		1.0
PORTREVISION=		1
CATEGORIES=		mail www
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		ports@FreeBSD.org
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

OPTIONS_DEFINE=	SIEVE CALENDR LDAPPW SQLPW MAILFT LGAUTH LGNOTES \
		MLOGIN NOTES NOTIFY PW4GET PUPDATE QMADMIN QUOTA \
		SASQL BUTTONS SLOGIN TIMEOUT TMDA VLOGIN WEBSRCH \
		WETTER
SIEVE_DESC=	Sieve Mail Filters plugin
CALENDR_DESC=	Shared Calendars plugin
LDAPPW_DESC=	Change LDAP passwords plugin
SQLPW_DESC=	Change *SQL passwords plugin
MAILFT_DESC=	E-mail footer plugin
LGAUTH_DESC=	HTTP-auth based login plugin
LGNOTES_DESC=	Notes on login screen plugin
MLOGIN_DESC=	Multilogin plugin
NOTES_DESC=	Notes plugin
NOTIFY_DESC=	New mail notify plugin
PW4GET_DESC=	Password forget plugin
PUPDATE_DESC=	Plugin update check plugin
QMADMIN_DESC=	Qmailadmin login plugin
QUOTA_DESC=	Quota usage plugin
SASQL_DESC=	SpamAssassin SQL plugin
BUTTONS_DESC=	Custom (spam/ham/etc.) buttons
SLOGIN_DESC=	SSL login plugin
TIMEOUT_DESC=	User session timeout plugin
TMDA_DESC=	TMDA plugin
VLOGIN_DESC=	Multi-site-hosting capabilities plugin
WEBSRCH_DESC=	Web search engines plugin
WETTER_DESC=	Weather in Germany plugin

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSIEVE}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/avelsieve:${PORTSDIR}/mail/squirrelmail-avelsieve-plugin
.endif

.if ${PORT_OPTIONS:MCALENDR}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/calendar:${PORTSDIR}/mail/squirrelmail-shared_calendars-plugin
.endif

.if ${PORT_OPTIONS:MLDAPPW}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/change_ldappass:${PORTSDIR}/mail/squirrelmail-change_ldappass-plugin
.endif

.if ${PORT_OPTIONS:MSQLPW}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/change_sqlpass:${PORTSDIR}/mail/squirrelmail-change_sqlpass-plugin
.endif

.if ${PORT_OPTIONS:MMAILFT}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/email_footer:${PORTSDIR}/mail/squirrelmail-email_footer-plugin
.endif

.if ${PORT_OPTIONS:MLGAUTH}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/login_auth:${PORTSDIR}/mail/squirrelmail-login_auth-plugin
.endif

.if ${PORT_OPTIONS:MLGNOTES}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/login_notes:${PORTSDIR}/mail/squirrelmail-login_notes-plugin
.endif

.if ${PORT_OPTIONS:MMLOGIN}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/multilogin:${PORTSDIR}/mail/squirrelmail-multilogin-plugin
.endif
# requires compatibility1 plugin - breaks other plugins
#.if ${PORT_OPTIONS:MNEWUSER}
#RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/newuser_wiz:${PORTSDIR}/mail/squirrelmail-newuser_wiz-plugin
#.endif

.if ${PORT_OPTIONS:MNOTES}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/notes:${PORTSDIR}/mail/squirrelmail-notes-plugin
.endif

.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/notify:${PORTSDIR}/mail/squirrelmail-notify-plugin
.endif

.if ${PORT_OPTIONS:MPW4GET}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/password_forget:${PORTSDIR}/mail/squirrelmail-password_forget-plugin
.endif

.if ${PORT_OPTIONS:MPUPDATE}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/pupdate:${PORTSDIR}/mail/squirrelmail-pupdate-plugin
.endif

.if ${PORT_OPTIONS:MQMADMIN}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/qmailadmin_login:${PORTSDIR}/mail/squirrelmail-qmailadmin_login-plugin
.endif

.if ${PORT_OPTIONS:MQUOTA}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/quota_usage:${PORTSDIR}/mail/squirrelmail-quota_usage-plugin
.endif

.if ${PORT_OPTIONS:MSASQL}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/sasql:${PORTSDIR}/mail/squirrelmail-sasql-plugin
.endif

.if ${PORT_OPTIONS:MBUTTONS}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/spam_buttons:${PORTSDIR}/mail/squirrelmail-spam-buttons-plugin
.endif

.if ${PORT_OPTIONS:MSLOGIN}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/secure_login:${PORTSDIR}/mail/squirrelmail-secure_login-plugin
.endif

.if ${PORT_OPTIONS:MTIMEOUT}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/timeout_user:${PORTSDIR}/mail/squirrelmail-timeout_user-plugin
.endif

.if ${PORT_OPTIONS:MTMDA}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/tmdatools:${PORTSDIR}/mail/squirrelmail-tmda-plugin
.endif

.if ${PORT_OPTIONS:MVLOGIN}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/vlogin:${PORTSDIR}/mail/squirrelmail-vlogin-plugin
.endif

.if ${PORT_OPTIONS:MWEBSRCH}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/web_search:${PORTSDIR}/mail/squirrelmail-websearch-plugin
.endif

.if ${PORT_OPTIONS:MWETTER}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/wetteronline:${PORTSDIR}/mail/squirrelmail-wetteronline-plugin
.endif

do-install: build
	@${DO_NADA}

.include <bsd.port.post.mk>

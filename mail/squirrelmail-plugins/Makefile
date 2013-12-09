# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		squirrelmail-plugins
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=		mail www
MASTER_SITES=	# none
DISTFILES=		# none

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A "meta-port" to install SquirrelMail plugins

NO_BUILD=	yes
NO_MTREE=	yes

SQUIRRELDIR?=	${PREFIX}/www/squirrelmail

OPTIONS_DEFINE=	BUTTONS CALENDAR LDAPPW LGAUTH LGNOTES MAILFT MLOGIN \
	NOTES NOTIFY PUPDATE PW4GET QMADMIN QUOTA SASQL SIEVE SLOGIN \
	SQLPW TIMEOUT TMDA VLOGIN WEBSEARCH WETTER

BUTTONS_DESC=	Custom (spam/ham/etc.) buttons
BUTTONS_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/spam_buttons:${PORTSDIR}/mail/squirrelmail-spam-buttons-plugin

CALENDAR_DESC=	Shared Calendars plugin
CALENDAR_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/calendar:${PORTSDIR}/mail/squirrelmail-shared_calendars-plugin

LDAPPW_DESC=	Change LDAP passwords plugin
LDAPPW_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/change_ldappass:${PORTSDIR}/mail/squirrelmail-change_ldappass-plugin

LGAUTH_DESC=	HTTP-auth based login plugin
LGAUTH_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/login_auth:${PORTSDIR}/mail/squirrelmail-login_auth-plugin

LGNOTES_DESC=	Notes on login screen plugin
LGNOTES_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/login_notes:${PORTSDIR}/mail/squirrelmail-login_notes-plugin

MAILFT_DESC=	E-mail footer plugin
MAILFT_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/email_footer:${PORTSDIR}/mail/squirrelmail-email_footer-plugin

MLOGIN_DESC=	Multilogin plugin
MLOGIN_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/multilogin:${PORTSDIR}/mail/squirrelmail-multilogin-plugin

NOTES_DESC=	Notes plugin
NOTES_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/notes:${PORTSDIR}/mail/squirrelmail-notes-plugin

NOTIFY_DESC=	New mail notify plugin
NOTIFY_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/notify:${PORTSDIR}/mail/squirrelmail-notify-plugin

PUPDATE_DESC=	Plugin update check plugin
PUPDATE_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/pupdate:${PORTSDIR}/mail/squirrelmail-pupdate-plugin

PW4GET_DESC=	Password forget plugin
PW4GET_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/password_forget:${PORTSDIR}/mail/squirrelmail-password_forget-plugin

QMADMIN_DESC=	Qmailadmin login plugin
QMADMIN_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/qmailadmin_login:${PORTSDIR}/mail/squirrelmail-qmailadmin_login-plugin

QUOTA_DESC=	Quota usage plugin
QUOTA_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/quota_usage:${PORTSDIR}/mail/squirrelmail-quota_usage-plugin

SASQL_DESC=	SpamAssassin SQL plugin
SASQL_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/sasql:${PORTSDIR}/mail/squirrelmail-sasql-plugin

SIEVE_DESC=	Sieve Mail Filters plugin
SIEVE_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/avelsieve:${PORTSDIR}/mail/squirrelmail-avelsieve-plugin

SLOGIN_DESC=	SSL login plugin
SLOGIN_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/secure_login:${PORTSDIR}/mail/squirrelmail-secure_login-plugin

SQLPW_DESC=	Change *SQL passwords plugin
SQLPW_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/change_sqlpass:${PORTSDIR}/mail/squirrelmail-change_sqlpass-plugin

TIMEOUT_DESC=	User session timeout plugin
TIMEOUT_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/timeout_user:${PORTSDIR}/mail/squirrelmail-timeout_user-plugin

TMDA_DESC=	TMDA plugin
TMDA_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/tmdatools:${PORTSDIR}/mail/squirrelmail-tmda-plugin

VLOGIN_DESC=	Multi-site-hosting capabilities plugin
VLOGIN_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/vlogin:${PORTSDIR}/mail/squirrelmail-vlogin-plugin

WEBSEARCH_DESC=	Web search engines plugin
WEBSEARCH_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/web_search:${PORTSDIR}/mail/squirrelmail-websearch-plugin

WETTER_DESC=	Weather in Germany plugin
WETTER_RUN_DEPENDS=	${SQUIRRELDIR}/plugins/wetteronline:${PORTSDIR}/mail/squirrelmail-wetteronline-plugin

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>

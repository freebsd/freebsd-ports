# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	squirrelmail-plugins
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	mail www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"meta-port" to install SquirrelMail plugins

SQUIRRELDIR?=	${PREFIX}/www/squirrelmail

OPTIONS_DEFINE=	BUTTONS CALENDAR LDAPPW LGAUTH LGNOTES MAILFT MLOGIN \
	NOTES NOTIFY PUPDATE PW4GET QMADMIN QUOTA SASQL SIEVE SLOGIN \
	SQLPW TIMEOUT TMDA VLOGIN WEBSEARCH WETTER

BUTTONS_DESC=	Custom (spam/ham/etc.) buttons
BUTTONS_RUN_DEPENDS=	squirrelmail-spam-buttons-plugin>0:mail/squirrelmail-spam-buttons-plugin

CALENDAR_DESC=	Shared Calendars plugin
CALENDAR_RUN_DEPENDS=	squirrelmail-shared_calendars-plugin>0:mail/squirrelmail-shared_calendars-plugin

LDAPPW_DESC=	Change LDAP passwords plugin
LDAPPW_RUN_DEPENDS=	squirrelmail-change_ldappass-plugin>0:mail/squirrelmail-change_ldappass-plugin

LGAUTH_DESC=	HTTP-auth based login plugin
LGAUTH_RUN_DEPENDS=	squirrelmail-login_auth-plugin>0:mail/squirrelmail-login_auth-plugin

LGNOTES_DESC=	Notes on login screen plugin
LGNOTES_RUN_DEPENDS=	squirrelmail-login_notes-plugin>0:mail/squirrelmail-login_notes-plugin

MAILFT_DESC=	E-mail footer plugin
MAILFT_RUN_DEPENDS=	squirrelmail-email_footer-plugin>0:mail/squirrelmail-email_footer-plugin

MLOGIN_DESC=	Multilogin plugin
MLOGIN_RUN_DEPENDS=	squirrelmail-multilogin-plugin>0:mail/squirrelmail-multilogin-plugin

NOTES_DESC=	Notes plugin
NOTES_RUN_DEPENDS=	squirrelmail-notes-plugin>0:mail/squirrelmail-notes-plugin

NOTIFY_DESC=	New mail notify plugin
NOTIFY_RUN_DEPENDS=	squirrelmail-notify-plugin>0:mail/squirrelmail-notify-plugin

PUPDATE_DESC=	Plugin update check plugin
PUPDATE_RUN_DEPENDS=	squirrelmail-pupdate-plugin>0:mail/squirrelmail-pupdate-plugin

PW4GET_DESC=	Password forget plugin
PW4GET_RUN_DEPENDS=	squirrelmail-password_forget-plugin>0:mail/squirrelmail-password_forget-plugin

QMADMIN_DESC=	Qmailadmin login plugin
QMADMIN_RUN_DEPENDS=	squirrelmail-qmailadmin_login-plugin>0:mail/squirrelmail-qmailadmin_login-plugin

QUOTA_DESC=	Quota usage plugin
QUOTA_RUN_DEPENDS=	squirrelmail-quota_usage-plugin>0:mail/squirrelmail-quota_usage-plugin

SASQL_DESC=	SpamAssassin SQL plugin
SASQL_RUN_DEPENDS=	squirrelmail-sasql-plugin>0:mail/squirrelmail-sasql-plugin

SIEVE_DESC=	Sieve Mail Filters plugin
SIEVE_RUN_DEPENDS=	squirrelmail-avelsieve-plugin>0:mail/squirrelmail-avelsieve-plugin

SLOGIN_DESC=	SSL login plugin
SLOGIN_RUN_DEPENDS=	squirrelmail-secure_login-plugin>0:mail/squirrelmail-secure_login-plugin

SQLPW_DESC=	Change *SQL passwords plugin
SQLPW_RUN_DEPENDS=	squirrelmail-change-sqlpass-plugin>0:mail/squirrelmail-change_sqlpass-plugin

TIMEOUT_DESC=	User session timeout plugin
TIMEOUT_RUN_DEPENDS=	squirrelmail-timeout_user-plugin>0:mail/squirrelmail-timeout_user-plugin

TMDA_DESC=	TMDA plugin
TMDA_RUN_DEPENDS=	squirrelmail-tmda-plugin>0:mail/squirrelmail-tmda-plugin

VLOGIN_DESC=	Multi-site-hosting capabilities plugin
VLOGIN_RUN_DEPENDS=	squirrelmail-vlogin-plugin>0:mail/squirrelmail-vlogin-plugin

WEBSEARCH_DESC=	Web search engines plugin
WEBSEARCH_RUN_DEPENDS=	squirrelmail-web_search-plugin>0:mail/squirrelmail-websearch-plugin

WETTER_DESC=	Weather in Germany plugin
WETTER_RUN_DEPENDS=	squirrelmail-wetteronline-plugin>0:mail/squirrelmail-wetteronline-plugin

USES=		metaport

.include <bsd.port.mk>

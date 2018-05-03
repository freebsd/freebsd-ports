# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	squirrelmail-plugins
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	mail www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"meta-port" to install SquirrelMail plugins

SQUIRRELDIR?=	${PREFIX}/www/squirrelmail

OPTIONS_DEFINE=	BUTTONS CALENDAR LDAPPW LGAUTH LGNOTES MAILFT MLOGIN \
	NOTES NOTIFY PUPDATE PW4GET QMADMIN QUOTA SASQL SIEVE SLOGIN \
	SQLPW TIMEOUT TMDA VLOGIN WEBSEARCH WETTER

BUTTONS_DESC=	Custom (spam/ham/etc.) buttons
BUTTONS_RUN_DEPENDS=	squirrelmail-spam-buttons-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-spam-buttons-plugin@${PHP_FLAVOR}

CALENDAR_DESC=	Shared Calendars plugin
CALENDAR_RUN_DEPENDS=	squirrelmail-shared_calendars-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-shared_calendars-plugin@${PHP_FLAVOR}

LDAPPW_DESC=	Change LDAP passwords plugin
LDAPPW_RUN_DEPENDS=	squirrelmail-change_ldappass-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-change_ldappass-plugin@${PHP_FLAVOR}

LGAUTH_DESC=	HTTP-auth based login plugin
LGAUTH_RUN_DEPENDS=	squirrelmail-login_auth-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-login_auth-plugin@${PHP_FLAVOR}

LGNOTES_DESC=	Notes on login screen plugin
LGNOTES_RUN_DEPENDS=	squirrelmail-login_notes-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-login_notes-plugin@${PHP_FLAVOR}

MAILFT_DESC=	E-mail footer plugin
MAILFT_RUN_DEPENDS=	squirrelmail-email_footer-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-email_footer-plugin@${PHP_FLAVOR}

MLOGIN_DESC=	Multilogin plugin
MLOGIN_RUN_DEPENDS=	squirrelmail-multilogin-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-multilogin-plugin@${PHP_FLAVOR}

NOTES_DESC=	Notes plugin
NOTES_RUN_DEPENDS=	squirrelmail-notes-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-notes-plugin@${PHP_FLAVOR}

NOTIFY_DESC=	New mail notify plugin
NOTIFY_RUN_DEPENDS=	squirrelmail-notify-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-notify-plugin@${PHP_FLAVOR}

PUPDATE_DESC=	Plugin update check plugin
PUPDATE_RUN_DEPENDS=	squirrelmail-pupdate-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-pupdate-plugin@${PHP_FLAVOR}

PW4GET_DESC=	Password forget plugin
PW4GET_RUN_DEPENDS=	squirrelmail-password_forget-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-password_forget-plugin@${PHP_FLAVOR}

QMADMIN_DESC=	Qmailadmin login plugin
QMADMIN_RUN_DEPENDS=	squirrelmail-qmailadmin_login-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-qmailadmin_login-plugin@${PHP_FLAVOR}

QUOTA_DESC=	Quota usage plugin
QUOTA_RUN_DEPENDS=	squirrelmail-quota_usage-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-quota_usage-plugin@${PHP_FLAVOR}

SASQL_DESC=	SpamAssassin SQL plugin
SASQL_RUN_DEPENDS=	squirrelmail-sasql-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-sasql-plugin@${PHP_FLAVOR}

SIEVE_DESC=	Sieve Mail Filters plugin
SIEVE_RUN_DEPENDS=	squirrelmail-avelsieve-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-avelsieve-plugin@${PHP_FLAVOR}

SLOGIN_DESC=	SSL login plugin
SLOGIN_RUN_DEPENDS=	squirrelmail-secure_login-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-secure_login-plugin@${PHP_FLAVOR}

SQLPW_DESC=	Change *SQL passwords plugin
SQLPW_RUN_DEPENDS=	squirrelmail-change-sqlpass-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-change_sqlpass-plugin@${PHP_FLAVOR}

TIMEOUT_DESC=	User session timeout plugin
TIMEOUT_RUN_DEPENDS=	squirrelmail-timeout_user-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-timeout_user-plugin@${PHP_FLAVOR}

TMDA_DESC=	TMDA plugin
TMDA_RUN_DEPENDS=	squirrelmail-tmda-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-tmda-plugin@${PHP_FLAVOR}

VLOGIN_DESC=	Multi-site-hosting capabilities plugin
VLOGIN_RUN_DEPENDS=	squirrelmail-vlogin-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-vlogin-plugin@${PHP_FLAVOR}

WEBSEARCH_DESC=	Web search engines plugin
WEBSEARCH_RUN_DEPENDS=	squirrelmail-web_search-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-websearch-plugin@${PHP_FLAVOR}

WETTER_DESC=	Weather in Germany plugin
WETTER_RUN_DEPENDS=	squirrelmail-wetteronline-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-wetteronline-plugin@${PHP_FLAVOR}

USES=		metaport php:flavors

.include <bsd.port.mk>

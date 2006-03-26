# New ports collection makefile for:		squirrelmail-change_ldappass-plugin
# Date created:		3 Jul 2005
# Whom:		Alexander Wittig <alexander@wittig.name>
#
# $FreeBSD$

PORTNAME=		squirrelmail-${SQUIRREL_PLUGIN_NAME}-plugin
PORTVERSION=		1.8
CATEGORIES=		mail www
MASTER_SITES=		http://www.squirrelmail.org/plugins/
DISTNAME=		${SQUIRREL_PLUGIN_NAME}-${PORTVERSION}
DIST_SUBDIR=		squirrelmail

MAINTAINER=		alexander@wittig.name
COMMENT=		Allows users to change their passwords stored in LDAP Tree

RUN_DEPENDS=		${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail \
			${SQUIRRELDIR}/plugins/compatibility:${PORTSDIR}/mail/squirrelmail-compatibility-plugin

SQUIRREL_PLUGIN_NAME=	change_ldappass

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

NO_BUILD=		yes
NO_WRKSUBDIR=		yes
USE_PERL5_BUILD=	yes
USE_PHP=		ldap
WANT_PHP_WEB=		yes

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
	${CP} -rp ${WRKSRC}/${SQUIRREL_PLUGIN_NAME} ${SQUIRRELDIR}/plugins
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

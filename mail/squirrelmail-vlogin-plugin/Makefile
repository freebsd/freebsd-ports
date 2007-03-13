# New ports collection makefile for:	squirrelmail-vlogin-plugin
# Date created:		10 Oct 2005
# Whom:		Matt Emmerton <matt@gsicomp.on.ca>
#
# $FreeBSD$

PORTNAME=		vlogin
PORTVERSION=		3.9.2
CATEGORIES=		mail www
MASTER_SITES=		http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=		squirrelmail-
PKGNAMESUFFIX=		-plugin
DISTNAME=		${PORTNAME}-${PORTVERSION}-1.2.7
DIST_SUBDIR=		squirrelmail

MAINTAINER=		neil@darlow.co.uk
COMMENT=		Adds multi-site-hosting capabilities to SquirrelMail

RUN_DEPENDS=		${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail \
			squirrelmail-compatibility-plugin>=2.0.5:${PORTSDIR}/mail/squirrelmail-compatibility-plugin

SQUIRREL_PLUGIN_NAME=	${PORTNAME}

.ifdef SQUIRRELDIR
PLIST_SUB+=		SQUIRRELDIR=${SQUIRRELDIR}
.else
.	ifndef WITHOUT_WWWDIR
SQUIRRELDIR=		${PREFIX}/www/squirrelmail
PLIST_SUB+=		SQUIRRELDIR=www/squirrelmail
.	else
SQUIRRELDIR=		${PREFIX}/squirrelmail
PLIST_SUB+=		SQUIRRELDIR=squirrelmail
.	endif
.endif
PLIST_SUB+=		SQUIRREL_PLUGIN_NAME=${SQUIRREL_PLUGIN_NAME}

NO_BUILD=		yes
NO_WRKSUBDIR=		yes
USE_PERL5_BUILD=	yes
WANT_PHP_WEB=		yes

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>

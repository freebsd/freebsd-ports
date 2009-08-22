# New ports collection makefile for:   fruity
# Date created:        29 December 2006
# Whom:                Dan Langille <dan@langille.org>
#
# $FreeBSD$
#

PORTNAME=	fruity
DISTVERSION=	1.0-rc2
PORTREVISION=	3
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.0-rc2

MAINTAINER=	dan@langille.org
COMMENT=	Fruity is a PHP based web-frontend to your Nagios configuration

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

NO_BUILD=	yes

SUB_FILES=	pkg-message patch-includes-config.inc fruity.config.inc

WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=4
DEFAULT_PHP_VER=5
USE_MYSQL=	yes
SUB_LIST+=	REQ_MYSQL=mysql
USE_PHP=	mysql session dba pcre

.include <bsd.port.pre.mk>

post-patch:
# the files directory contains a patch for the original file
# this removes the original copy created by that patch
	@${RM} ${WRKSRC}/includes/config.inc.orig
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/includes/config.inc

# the above replace create this file, which needs to be removed
	@${RM} ${WRKSRC}/includes/config.inc.bak

do-install:
	@${ECHO} "Installing in ${PREFIX}/www/fruity"
	${MKDIR} ${PREFIX}/www/fruity
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/fruity
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/fruity

post-install:
	@${CP} ${WRKDIR}/fruity.config.inc ${PREFIX}/etc/fruity.config.inc-sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

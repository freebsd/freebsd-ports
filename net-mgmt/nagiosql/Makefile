# New ports collection makefile for:	nagiosql
# Date created:			7 Dec 2010
# Whom:				Chris St Denis <chris@smartt.com>
#
# $FreeBSD$
#

PORTNAME=	nagiosql
PORTVERSION=	3.1.1
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NagiosQL%20${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//g}

MAINTAINER=	chris@smartt.com
COMMENT=	A web based administration tool for Nagios

RUN_DEPENDS=	nagios:${PORTSDIR}/net-mgmt/nagios \
		${PEARDIR}/HTML/Template/IT.php:${PORTSDIR}/devel/pear-HTML_Template_IT

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_MYSQL=	yes
USE_GETTEXT=	yes
USE_PHP=	mysql gettext ftp session simplexml
IGNORE_WITH_PHP=4
WANT_PHP_WEB=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PEARDIR?=	${LOCALBASE}/share/pear

OPTIONS=	CURL "Configure with cURL support" off \
		SSH2 "Configure with SSH2 support" off

#.include <bsd.port.pre.mk>

.if defined(WITH_CURL)
USE_PHP+=	curl
.endif

.if defined(WITH_SSH2)
USE_PHP+=	ssh2
.endif

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/${PORTNAME}/ ${WWWDIR}
	${CHOWN} ${WWWOWN}:${WWWGROUP} ${WWWDIR}/config

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

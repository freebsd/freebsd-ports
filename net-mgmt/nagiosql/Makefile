# New ports collection makefile for:	nagiosql
# Date created:			7 Dec 2010
# Whom:				Chris St Denis <chris@smartt.com>
#
# $FreeBSD$
#

PORTNAME=	nagiosql
PORTVERSION=	3.0.4
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NagiosQL%20${PORTVERSION}/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	chris@smartt.com
COMMENT=	A web based administration tool for Nagios

RUN_DEPENDS=	nagios:${PORTSDIR}/net-mgmt/nagios \
		${PEARDIR}/HTML/Template/IT.php:${PORTSDIR}/devel/pear-HTML_Template_IT

USE_BZIP2=	yes
USE_MYSQL=	yes
USE_GETTEXT=	yes
USE_PHP=	mysql gettext ftp session
IGNORE_WITH_PHP=4
WANT_PHP_WEB=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PEARDIR?=	${LOCALBASE}/share/pear
NAGIOSQL_FILES=	admin admin.php config favicon.ico functions images index.php install templates

do-install:
	${MKDIR} ${WWWDIR}
.for i in ${NAGIOSQL_FILES}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor
	${CHOWN} ${WWWOWN}:${WWWGROUP} ${WWWDIR}/config

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

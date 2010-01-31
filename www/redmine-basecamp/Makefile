# New ports collection makefile for:	redmine-basecamp
# Date created:		2010-01-16
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	basecamp
PORTVERSION=	20091116
CATEGORIES=	www
MASTER_SITES=	http://home.bluelife.at/ports/distfiles/ \
		http://tmp.chruetertee.ch/
PKGNAMEPREFIX=	redmine-

MAINTAINER=	decke@bluelife.at
COMMENT=	Basecamp Theme for Redmine

RUN_DEPENDS=	redmine>=0.9:${PORTSDIR}/www/redmine

USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
WWWDIR?=	${PREFIX}/www/redmine/public/themes/${PORTNAME}

PLIST_FILES=	%%WWWDIR%%/stylesheets/application.css
PLIST_DIRS=	%%WWWDIR%%/stylesheets \
		%%WWWDIR%%

do-install:
		${MKDIR} ${WWWDIR}
		cd ${WRKSRC} && ${PAX} -r -w . ${WWWDIR}

.include <bsd.port.mk>

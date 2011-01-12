# New ports collection makefile for:	redmine-basecamp
# Date created:		2010-01-16
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	basecamp
PORTVERSION=	20101203
CATEGORIES=	www
MASTER_SITES=	http://home.bluelife.at/ports/distfiles/ \
		LOCAL/decke
PKGNAMEPREFIX=	redmine-

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Basecamp Theme for Redmine

RUN_DEPENDS=	redmine>=0.9:${PORTSDIR}/www/redmine

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
WWWDIR?=	${PREFIX}/www/redmine/public/themes/${PORTNAME}

PLIST_FILES=	%%WWWDIR%%/README.md \
		%%WWWDIR%%/stylesheets/application.css
PLIST_DIRS=	%%WWWDIR%%/stylesheets \
		%%WWWDIR%%

do-install:
		${MKDIR} ${WWWDIR}
		cd ${WRKSRC} && ${PAX} -r -w . ${WWWDIR}

.include <bsd.port.mk>

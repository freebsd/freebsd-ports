# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	basecamp
PORTVERSION=	20130325
CATEGORIES=	www
PKGNAMEPREFIX=	redmine-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basecamp Theme for Redmine

LICENSE=	MIT

RUN_DEPENDS=	redmine>=0.9:www/redmine

USE_GITHUB=	yes
GH_ACCOUNT=	theill
GH_PROJECT=	redmine-basecamp-theme
GH_TAGNAME=	6812d61

NO_ARCH=	yes
NO_BUILD=	yes

WWWDIR?=	${PREFIX}/www/redmine/public/themes/${PORTNAME}

PLIST_FILES=	%%WWWDIR%%/README.md \
		%%WWWDIR%%/stylesheets/application.css

do-install:
		${MKDIR} ${STAGEDIR}${WWWDIR}
		cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

PORTNAME=	sauserprefs
PORTVERSION=	1.20
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	stb@lassitu.de
COMMENT=	Roundcube plugin to manage SpamAssassin prefs
WWW=		http://www.tehinterweb.co.uk/roundcube/

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.5:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=83

WWWDIR=		${PREFIX}/www/roundcube/plugins/sauserprefs
NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	JohnDoh
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}/${WWWDIR}

.include <bsd.port.mk>

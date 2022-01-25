PORTNAME=	html5_notifier
PORTVERSION=	0.6.4
DISTVERSIONPREFIX=	v
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	meta@FreeBSD.org
COMMENT=	HTML5 desktop notifier plugin for roundcube

LICENSE=	GPLv3

BUILD_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}
RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
USE_GITHUB=	yes
GH_ACCOUNT=	stremlau
IGNORE_WITH_PHP=	81

WWWDIR=		${PREFIX}/www/roundcube/plugins/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

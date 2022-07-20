PORTNAME=	carddav
PORTVERSION=	4.3.0
DISTVERSIONPREFIX=v
CATEGORIES=	mail
MASTER_SITES=	https://github.com/mstilkerich/rcmcarddav/releases/download/${DISTVERSIONFULL}/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Roundcube CardDAV plugin

LICENSE=	GPLv2

IGNORE_WITH_PHP=81 82

BUILD_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}
RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors

NO_BUILD=	yes
NO_ARCH=	yes

USE_PHP=	curl dom simplexml sockets tokenizer xml xmlreader xmlwriter

WRKSRC=		${WRKDIR}/${PORTNAME}
WWWDIR=		${PREFIX}/www/roundcube/plugins/carddav

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}/)

.include <bsd.port.mk>

# Created by: gahr

PORTNAME=	carddav
PORTVERSION=	4.0.4
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	LOCAL/gahr https://people.freebsd.org/~gahr/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-vendor

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Roundcube CardDAV plugin

LICENSE=	GPLv2

BUILD_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}
RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors tar:bz2

NO_BUILD=	yes
NO_ARCH=	yes

USE_PHP=	curl dom simplexml sockets tokenizer xml xmlreader xmlwriter
IGNORE_WITH_PHP=81

WWWDIR=		${PREFIX}/www/roundcube/plugins/carddav

do-install:
	${FIND} ${WRKSRC} -name "*.orig" -delete
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

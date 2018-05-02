# Created by: gahr
# $FreeBSD$

PORTNAME=	carddav
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	https://github.com/blind-coder/rcmcarddav/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Roundcube CardDAV plugin

LICENSE=	GPLv2

BUILD_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}
RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
NO_ARCH=	yes

# Cannot use USE_GITHUB, as the original tarball doesn't come with the bundled
# sabre library.
#USE_GITHUB=	yes
#GH_ACCOUNT=	blind-coder
#GH_PROJECT=	rcmcarddav

USES=		php:flavors tar:bz2
USE_PHP=	simplexml sockets curl

WWWDIR=		${PREFIX}/www/roundcube/plugins/carddav

do-install:
	${FIND} ${WRKSRC} -name "*.orig" -delete
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

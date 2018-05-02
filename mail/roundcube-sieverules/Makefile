# Created by: Anes Muhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	sieverules
DISTVERSION=	2.3
PORTEPOCH=	1
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Roundcube webmail sieve plugin

LICENSE=	GPLv3

BUILD_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}
RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
USE_GITHUB=	yes
GH_ACCOUNT=	johndoh
GH_PROJECT=	roundcube-sieverules
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

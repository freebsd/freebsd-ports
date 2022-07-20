PORTNAME=	umich
PORTVERSION=	20090813
CATEGORIES=	mail
MASTER_SITES=	ftp://renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Theme for RoundCube Web Mail

LICENSE=	GPLv3+ # same as roundcube's

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.2:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=	81 82

WWWDIR?=	${PREFIX}/www/roundcube/skins/umich
NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

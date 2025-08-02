PORTNAME=	twofactor_gauthenticator
PORTVERSION=	g20231119
CATEGORIES=	mail security
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Roundcube TOTP auth plugin
WWW=		https://github.com/alexandregz/twofactor_gauthenticator

LICENSE=	GPLv2

BUILD_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}
RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors

USE_GITHUB=	yes
GH_ACCOUNT=	alexandregz
GH_TAGNAME=	23d8f4c

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

WWWDIR=		${PREFIX}/www/roundcube/plugins/${PORTNAME}

post-patch:
	@${RM} ${WRKSRC}/docker-compose.yaml

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}
	cd ${STAGEDIR}${WWWDIR} && \
		${MV} config.inc.php.dist config.inc.php.sample

.include <bsd.port.mk>

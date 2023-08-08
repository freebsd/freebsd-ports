PORTNAME=	classic
DISTVERSION=	1.6.0
CATEGORIES?=	mail www
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Larry skin/theme for Rouncube webmail
WWW=		https://github.com/roundcube/classic/

LICENSE=	GPLv3+

USES=		cpe php:flavors

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.6.0:mail/roundcube@${PHP_FLAVOR}
NO_ARCH=	yes
NO_BUILD=	yes

CPE_PRODUCT=	webmail
CPE_VENDOR=	roundcube

IGNORE_WITH_PHP=82 83

WWWDIR=		${PREFIX}/www/${PKGNAMEPREFIX:S/-//}/skins/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	${PKGNAMEPREFIX:S/-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>

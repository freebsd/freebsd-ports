PORTNAME=	icinga-ipl-i18n
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	0
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Icinga PHP library
WWW=		https://github.com/Icinga/ipl-i18n

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:web,flavors

USE_GITHUB=	yes
GH_ACCOUNT=	icinga
GH_PROJECT=	ipl-i18n

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/icinga-php/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>

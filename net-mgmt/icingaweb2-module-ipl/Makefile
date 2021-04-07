PORTNAME=	icingaweb2-module-ipl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Icinga PHP library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.4.1:net-mgmt/icingaweb2@${PHP_FLAVOR}

USES=		php:web,flavors

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>

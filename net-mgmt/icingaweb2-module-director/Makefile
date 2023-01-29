PORTNAME=	icingaweb2-module-director
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.2
PORTREVISION=	1
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Configuration frontend for Icinga 2, integrated automation
WWW=		https://github.com/Icinga/icingaweb2-module-director

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.11.4:net-mgmt/icingaweb2@${PHP_FLAVOR}

USES=		php:web,flavors

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=		NLS

NLS_USES=	gettext
NLS_USE=	php=intl

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>

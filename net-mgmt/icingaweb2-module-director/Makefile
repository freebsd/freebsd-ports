PORTNAME=	icingaweb2-module-director
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.5
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Configuration frontend for Icinga 2, integrated automation
WWW=		https://github.com/Icinga/icingaweb2-module-director

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.12.1:net-mgmt/icingaweb2@${PHP_FLAVOR}

USES=		php:web,flavors
USE_PHP=	pcntl
IGNORE_WITH_PHP=81
USE_RC_SUBR=	icinga-director

DIRECTOR_USER?=		icingadirector
DIRECTOR_GROUP?=	icinga

USERS=		${DIRECTOR_USER}
GROUPS=		${DIRECTOR_GROUP}

SUB_LIST+=	DIRECTOR_GROUP=${DIRECTOR_GROUP} \
		DIRECTOR_USER=${DIRECTOR_USER}
PLIST_SUB+=	DIRECTOR_GROUP=${DIRECTOR_GROUP} \
		DIRECTOR_USER=${DIRECTOR_USER}

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_USE=	PHP=intl

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}/var/run/icinga-director
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>

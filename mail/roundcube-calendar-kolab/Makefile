PORTNAME=	calendar
PORTVERSION=	3.5.5
CATEGORIES=	mail
MASTER_SITES=	https://cgit.kolab.org/roundcubemail-plugins-kolab/snapshot/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	-kolab${PHP_PKGNAMESUFFIX}
DISTNAME=	roundcubemail-plugins-kolab-${DISTVERSION}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Roundcube Calendar plugin from Kolab

LICENSE=	AGPLv3

BUILD_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}
RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=80

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

WWWDIR=		${PREFIX}/www/roundcube/plugins

post-patch:
	${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
	    ${WRKSRC}/plugins/calendar/config.inc.php.dist
	${RM} ${WRKSRC}/plugins/calendar/config.inc.php.dist.*

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
.for d in calendar libcalendaring libkolab
	(cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} $d ${STAGEDIR}${WWWDIR}/)
.endfor
	${INSTALL_DATA} ${FILESDIR}/libkolab.min.css \
		${STAGEDIR}${WWWDIR}/libkolab/skins/elastic/

.include <bsd.port.mk>

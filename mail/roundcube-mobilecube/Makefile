# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>

PORTNAME=	mobilecube
PORTVERSION=	${THEME_VERSION}.${THEME_BUILD}
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${THEME_VERSION}%20Beta/Build%20%23${THEME_BUILD}/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	MobileCubeBeta%23${THEME_BUILD}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Theme for RoundCube Web Mail

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.3:mail/roundcube@${PHP_FLAVOR}

THEME_VERSION?=	3.1.0
THEME_BUILD?=	030110A

USES=		php:flavors zip
IGNORE_WITH_PHP=	81

WWWDIR?=	${PREFIX}/www/roundcube/skins/MobileCube
NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/MobileCubeBeta\#${THEME_BUILD}

post-patch:
	${FIND} ${WRKSRC} -type f -name '*.orig' -or -name '.DS_Store' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}/MobileCube && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

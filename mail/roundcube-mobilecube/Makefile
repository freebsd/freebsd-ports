# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	mobilecube
PORTVERSION=	${THEME_VERSION}.${THEME_BUILD}
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${THEME_VERSION}%20Beta/Build%20%23${THEME_BUILD}/
PKGNAMEPREFIX=	roundcube-
DISTNAME=	MobileCubeBeta%23${THEME_BUILD}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Theme for RoundCube Web Mail

RUN_DEPENDS=	roundcube>=0.3:mail/roundcube

THEME_VERSION?=	3.1.0
THEME_BUILD?=	030110A

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/MobileCubeBeta\#${THEME_BUILD}
WWWDIR?=	${PREFIX}/www/roundcube/skins/MobileCube

post-patch:
	${FIND} ${WRKSRC} -type f -name '*.orig' -or -name '.DS_Store' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}/MobileCube && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

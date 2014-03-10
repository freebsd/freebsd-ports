# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	mobilecube
PORTVERSION=	${THEME_VERSION}.${THEME_BUILD}
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${THEME_VERSION}%20Beta/Build%20%23${THEME_BUILD}/
PKGNAMEPREFIX=	roundcube-
DISTNAME=	MobileCubeBeta%23${THEME_BUILD}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Theme for RoundCube Web Mail

RUN_DEPENDS=	roundcube>=0.3:${PORTSDIR}/mail/roundcube

THEME_VERSION?=	3.1.0
THEME_BUILD?=	030110A

USES=		zip
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/MobileCubeBeta\#${THEME_BUILD}
WWWDIR?=	${PREFIX}/www/roundcube/skins/MobileCube

# This target is only meant to be used by the port maintainer.
x-generate-plist: build
	cd ${WRKSRC}/MobileCube; \
	${FIND} . ! -type d ! -name '*.orig' | ${SORT} | \
		${SED} -e "s,^\.,%%WWWDIR%%," >${.CURDIR}/pkg-plist.tmp ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
		-e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
		-e "s,^\.,@dirrm %%WWWDIR%%," >>${.CURDIR}/pkg-plist.tmp
NO_STAGE=	yes
post-patch:
	${FIND} ${WRKSRC} -type f -name '*.orig' -or -name '.DS_Store' -delete

do-install:
	${MKDIR} ${WWWDIR}
	cd ${WRKSRC}/MobileCube && ${PAX} -r -w . ${WWWDIR}

.include <bsd.port.mk>

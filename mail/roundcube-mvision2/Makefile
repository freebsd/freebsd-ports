# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	mvision2
PORTVERSION=	2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://roundcubethemes.net/downloads/ \
		ftp://renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Theme for RoundCube Web Mail

RUN_DEPENDS=	roundcube>=0.2:${PORTSDIR}/mail/roundcube

NO_BUILD=	yes

WWWDIR?=	${PREFIX}/www/roundcube/skins/mvision2_en

SUB_FILES=	pkg-message

# This target is only meant to be used by the port maintainer.
x-generate-plist: build
	cd ${WRKDIR}/mvision2_en; \
	${FIND} . ! -type d ! -name '*.orig' | ${SORT} | \
		${SED} -e "s,^\.,%%WWWDIR%%," >${.CURDIR}/pkg-plist.tmp ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
		-e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
		-e "s,^\.,@dirrm %%WWWDIR%%," >>${.CURDIR}/pkg-plist.tmp

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKDIR}/mvision2_en && ${PAX} -r -w . \
		${STAGEDIR}${WWWDIR}
	${FIND} ${STAGEDIR}${WWWDIR} -type f -exec ${CHMOD} 0644 {} \;

.include <bsd.port.mk>

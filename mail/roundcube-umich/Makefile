# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	umich
PORTVERSION=	20090813
CATEGORIES=	mail
MASTER_SITES=	ftp://renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Theme for RoundCube Web Mail

RUN_DEPENDS=	roundcube>=0.2:mail/roundcube

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/roundcube/skins/umich

post-patch:
	${FIND} ${WRKSRC} -type f -name '*.orig' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

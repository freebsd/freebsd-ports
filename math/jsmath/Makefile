# New ports collection makefile for:	jsMath
# Date created:		2006-02-23
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	jsMath
PORTVERSION=	3.4c
CATEGORIES=	math www
MASTER_SITES=	SFE

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A Javascript tool for including mathematics in web pages

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	IMAGE_FONTS "Enable image fonts" On \
		SPRITE_FONTS "Enable sprite fonts" Off

.include <bsd.port.pre.mk>

.if defined(WITH_IMAGE_FONTS)
RUN_DEPENDS+=	${WWWDIR}/fonts/cm-fonts/alpha/def.js:${PORTSDIR}/math/jsmath-fonts
.endif
.if defined(WITH_SPRITE_FONTS)
RUN_DEPENDS+=	${WWWDIR}/fonts-sprite/cm-fonts/font.js:${PORTSDIR}/math/jsmath-fonts-sprite
.endif

post-extract:
	@${RM} ${WRKSRC}/COPYING.txt

do-install:
	@${INSTALL} -d ${WWWDIR}
	@${CP} -Rp ${WRKSRC}/ ${WWWDIR}/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WWWDIR}/
	@${CHMOD} -R go-w ${WWWDIR}/

.include <bsd.port.post.mk>

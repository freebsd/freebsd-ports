# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	jsMath
DISTVERSION=	3.6e
CATEGORIES=	math www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	JavaScript tool for including mathematics in web pages

USES=		zip
NO_BUILD=	yes

OPTIONS_DEFINE=	IMAGE_FONTS SPRITE_FONTS
OPTIONS_DEFAULT=	IMAGE_FONTS
IMAGE_FONTS_DESC=	Image fonts
SPRITE_FONTS_DESC=	Sprite fonts

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIMAGE_FONTS}
RUN_DEPENDS+=	${WWWDIR}/fonts/cm-fonts/alpha/def.js:${PORTSDIR}/math/jsmath-fonts
.endif
.if ${PORT_OPTIONS:MSPRITE_FONTS}
RUN_DEPENDS+=	${WWWDIR}/fonts-sprite/cm-fonts/font.js:${PORTSDIR}/math/jsmath-fonts-sprite
.endif

post-extract:
	@${RM} ${WRKSRC}/COPYING.txt
	@${FIND} -d ${WRKSRC} -type d -name "CVS" -exec ${RM} -R {} ";"

do-install:
	@${INSTALL} -d ${WWWDIR}
	@${CP} -Rp ${WRKSRC}/ ${WWWDIR}/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WWWDIR}/
	@${CHMOD} -R go-w ${WWWDIR}/

.include <bsd.port.post.mk>

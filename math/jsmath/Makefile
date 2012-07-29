# New ports collection makefile for:	jsMath
# Date created:		2006-02-23
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	jsMath
DISTVERSION=	3.6e
CATEGORIES=	math www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	JavaScript tool for including mathematics in web pages

USE_ZIP=	yes
NO_BUILD=	yes

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
	@${FIND} -d ${WRKSRC} -type d -name "CVS" -exec ${RM} -R {} ";"

do-install:
	@${INSTALL} -d ${WWWDIR}
	@${CP} -Rp ${WRKSRC}/ ${WWWDIR}/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WWWDIR}/
	@${CHMOD} -R go-w ${WWWDIR}/

.include <bsd.port.post.mk>

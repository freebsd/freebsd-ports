# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	jsMath-fonts-sprite
PORTVERSION=	1.0
CATEGORIES=	math www
MASTER_SITES=	http://www.math.union.edu/~dpvc/jsMath/download/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A sprite fonts pack for jsMath

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}
WWWDIR?=	${PREFIX}/www/jsMath

.for _i in bx ex mi r sy ti
PLIST_SUB+=	D${_i}a=${WWWDIR_REL}/fonts-sprite/cm${_i}10/alpha
PLIST_SUB+=	D${_i}p=${WWWDIR_REL}/fonts-sprite/cm${_i}10/plain
PLIST_SUB+=	D${_i}j=${WWWDIR_REL}/fonts-sprite/cm${_i}10
.endfor
PLIST_SUB+=	Dcmj=${WWWDIR_REL}/fonts-sprite/cm-fonts

NO_STAGE=	yes
do-install:
	@${INSTALL} -d ${WWWDIR}/fonts-sprite
	@${CP} -Rp ${WRKSRC}/fonts-sprite ${WWWDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WWWDIR}/fonts-sprite
	@${CHMOD} -R go-w ${WWWDIR}/fonts-sprite

.include <bsd.port.mk>

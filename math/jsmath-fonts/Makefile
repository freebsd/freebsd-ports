# New ports collection makefile for:	jsMath-fonts
# Date created:		2006-02-23
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	jsMath-fonts
PORTVERSION=	1.3
CATEGORIES=	math www
MASTER_SITES=	http://www.math.union.edu/~dpvc/jsMath/download/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A raster fonts pack for jsmath

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/jsMath
WWWDIR?=	${PREFIX}/www/jsMath

.for _i in bx ex mi r sy ti
PLIST_SUB+=	D${_i}a=${WWWDIR_REL}/fonts/cm${_i}10/alpha
PLIST_SUB+=	D${_i}p=${WWWDIR_REL}/fonts/cm${_i}10/plain
.endfor
PLIST_SUB+=	Dcma=${WWWDIR_REL}/fonts/cm-fonts/alpha
PLIST_SUB+=	Dcmp=${WWWDIR_REL}/fonts/cm-fonts/plain

do-install:
	@${INSTALL} -d ${WWWDIR}/fonts
	@${CP} -Rp ${WRKSRC}/fonts/ ${WWWDIR}/fonts/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WWWDIR}/fonts/
	@${CHMOD} -R go-w ${WWWDIR}/fonts/

.include <bsd.port.mk>

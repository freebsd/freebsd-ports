# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	httprint
PORTVERSION=	301
CATEGORIES=	security
MASTER_SITES=	http://net-square.com/zip%20folders/
DISTNAME=	${PORTNAME}_freebsd_${PORTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Web server fingerprinting tool

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}/freebsd/
USES=		zip

RESTRICTED=	No cost for personal, education and non-commercial use.
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC} ${DATADIR}
	${LN} -s ${DATADIR}/httprint ${PREFIX}/bin

.include <bsd.port.mk>

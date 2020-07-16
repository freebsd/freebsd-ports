# Created by: Dreamcat4 <dreamcat4@gmail.com>
# $FreeBSD$

PORTNAME=	dtv-scan-tables
PORTVERSION=	20200311
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/decke

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Digital TV scan tables from linuxtv.org

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL

USES=		tar:xz

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "-not -name COPYING\*")

.include <bsd.port.mk>

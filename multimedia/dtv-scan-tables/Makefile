PORTNAME=	dtv-scan-tables
DISTVERSION=	2026-03-16
DISTVERSIONSUFFIX=	-7a595d06a6b0
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://linuxtv.org/downloads/dtv-scan-tables/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Digital TV scan tables from linuxtv.org
WWW=		https://linuxtv.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL

USES=		tar:bz2

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/usr/share/dvb

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "-not -name COPYING\*")

.include <bsd.port.mk>

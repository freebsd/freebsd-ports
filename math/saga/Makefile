# Ports collection makefile for:   saga
# Date created:        13 November 2009
# Whom:                rhurlin
#
# $FreeBSD$
#

PORTNAME=	saga
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/saga-gis/SAGA%20-%20${PORTVERSION:C/\.[[:digit:]]*$//}/SAGA%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src_linux

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	System for Automated Geoscientific Analyses

LIB_DEPENDS=	proj.6:${PORTSDIR}/graphics/proj \
		gdal.14:${PORTSDIR}/graphics/gdal \
		jasper.4:${PORTSDIR}/graphics/jasper \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${PORTNAME}-2.0

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

USE_WX=		2.8

post-patch:
	@for f in `${FIND} '${WRKSRC}' -name Makefile.in` \
		${WRKSRC}/configure; do \
		${REINPLACE_CMD} -e's|wx-config |${WX_CONFIG} |g' "$$f"; \
	done
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		${WRKSRC}/src/saga_core/saga_api/api_memory.cpp \
		${WRKSRC}/src/modules_projection/pj_georeference/pj_georeference/lmdif0.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

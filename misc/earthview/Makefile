# ex:ts=8
# Ports collection makefile for:	earthview
# Date created:			Sep 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	earthview
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc geography
MASTER_SITES=	http://fresh.t-systems-sfr.com/unix/src/privat2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produces a view output of an arbitrary region of the Earth

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_XORG=	xpm
CFLAGS+=	-I${LOCALBASE}/include
ALL_TARGET=	earthview

PLIST_FILES=	bin/earthview share/earthview/topography/topography.cps \
		share/earthview/topography/1440x720-2x2.az2 \
		share/earthview/population/population.cps \
		share/earthview/population/4320x2160-6x6.pz2
PLIST_DIRS=	share/earthview/topography share/earthview/population \
		share/earthview

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%CC%%|${CC}|g" \
		-e "s|%%CFLAGS%%|${CFLAGS}|g" -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/Makefile

pre-build:
	@${RM} -f ${WRKSRC}/earthview

.include <bsd.port.mk>

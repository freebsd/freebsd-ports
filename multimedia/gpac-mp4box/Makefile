# New ports collection makefile for:	gpac-mp4box
# Date created:				1 December 2006
# Whom:					Pascal Vizeli <pvizeli@yahoo.de>
#
# $FreeBSD$
#

PORTNAME=	mp4box
DISTVERSION=	0.4.5
CATEGORIES=	multimedia
MASTER_SITES=	SF/gpac/GPAC/GPAC%20${PORTVERSION}
PKGNAMEPREFIX=	gpac-
DISTNAME=	gpac-${DISTVERSION}

MAINTAINER=	pvizeli@yahoo.de
COMMENT=	A tool for merge mpg4 from Gpac

LIB_DEPENDS=	gpac.1:${PORTSDIR}/multimedia/gpac-libgpac

WRKSRC=		${WRKDIR}/gpac/applications/mp4box
PLIST_FILES=	bin/mp4box

pre-patch:
	${RM} -f ${WRKSRC}/Makefile

.include <bsd.port.mk>

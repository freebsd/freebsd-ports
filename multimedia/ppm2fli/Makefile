# New ports collection makefile for:	ppm2fli
# Date created:		7 Jan 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	ppm2fli
PORTVERSION=	b1
CATEGORIES=	graphics
MASTER_SITES=	ftp://crusty.er.usgs.gov/pub/animation/fli/
DISTNAME=	ppm2fli_b1.92
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	giffunip@asme.org

MAN1=	ppm2fli.1 unflick.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppm2fli ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unflick ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ppm2fli.man ${PREFIX}/man/man1/ppm2fli.1
	${INSTALL_MAN} ${WRKSRC}/unflick.man ${PREFIX}/man/man1/unflick.1

.include <bsd.port.mk>

# New ports collection makefile for:	endeavour
# Date created:		7 Oct 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	endeavour
PORTVERSION= 	1.07
CATEGORIES=	x11-fm
MASTER_SITES=	ftp://fox.mit.edu/pub/xsw/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib \
		Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/endeavour

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/endeavour ${PREFIX}/bin

.include <bsd.port.mk>

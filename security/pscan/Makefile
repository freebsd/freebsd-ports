# New ports collection makefile for:	pscan
# Date created:				02 September 2000
# Whom:					Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pscan
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.striker.ottawa.on.ca/~aland/pscan/
DISTNAME=	${PORTNAME}

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	#empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pscan ${PREFIX}/bin

.include <bsd.port.mk>

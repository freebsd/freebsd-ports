# New ports collection makefile for:	nte
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nte
PORTVERSION=	1.5a29
PORTREVISION=	1
CATEGORIES=	mbone tk80
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/nte/1.5a29/

MAINTAINER=	fenner@FreeBSD.org
COMMENT=	Multicast Network Text Editor

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/nte

PLIST_FILES=	bin/nte
USE_GMAKE=	yes
USE_X_PREFIX=	yes

MAKE_ENV=	LOCALBASE="${LOCALBASE}"

.include <bsd.port.mk>

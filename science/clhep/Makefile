# New ports collection makefile for:	clhep
# Date created:				6 May 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	clhep
PORTVERSION=	1.8.0.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://wwwasd.web.cern.ch/wwwasd/lhc++/export/share/CLHEP/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented toolkit for particle physics applications by CERN

WRKSRC=		${WRKDIR}/CLHEP

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	TARGET=${CONFIGURE_TARGET} VERSION=${PORTVERSION}

.include <bsd.port.mk>

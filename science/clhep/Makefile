# New ports collection makefile for:	clhep
# Date created:				6 May 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	clhep
PORTVERSION=	1.6.0.0
CATEGORIES=	science
MASTER_SITES=	http://wwwinfo.cern.ch/asd/lhc++/export/share/CLHEP/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Object-oriented toolkit for particle physics applications by CERN

WRKSRC=		${WRKDIR}/CLHEP
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_SUB=	TARGET=${CONFIGURE_TARGET}

.include <bsd.port.mk>

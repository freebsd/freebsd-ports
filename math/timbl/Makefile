# New ports collection makefile for: timbl
# Date created:		13 March 2008
# Whom:			Yuri Victorovich <yuri@tsoft.com>
#
# $FreeBSD$
#

PORTNAME=	timbl
PORTVERSION=	6.1.2
CATEGORIES=	math
MASTER_SITES=	http://ilk.uvt.nl/downloads/pub/software/

MAINTAINER=	yuri@tsoft.com
COMMENT=	Tilburg Memory Based Learner

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack

.include <bsd.port.mk>

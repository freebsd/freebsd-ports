# New ports collection makefile for:	dirac
# Date created:		11 May 2004
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dirac
PORTVERSION=	0.1.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Dirac-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Open source video codec from the BBC

LIB_DEPENDS=	xparam.1:${PORTSDIR}/devel/xparam

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	CXXFLAGS=-I${LOCALBASE}/include

NOMAN=		defined

.include <bsd.port.mk>

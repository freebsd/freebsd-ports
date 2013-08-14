# New ports collection makefile for:	dirac
# Date created:		11 May 2004
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dirac
PORTVERSION=	1.0.2
PORTREVISION?=	0
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-codec/Dirac-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	Open source video codec from the BBC

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack
USE_LDCONFIG=	yes

CONFIGURE_ENV?=	HAVE_LATEX=${FALSE} HAVE_DVIPDFM=${FALSE} \
		HAVE_DOXYGEN=${FALSE} HAVE_DOT=${FALSE}
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>

# New ports collection makefile for:	qtella
# Date created:				Sunday September 2nd, 2001
# Whom:					Jonathan Belson (jon@witchspace.com)
#
# $FreeBSD$
#

PORTNAME=		qtella
PORTVERSION=		0.5.3
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qtella

MAINTAINER=		jon@witchspace.com

HAS_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ARGS+=	--with-qt-dir=${X11BASE} --with-qt-moc=${X11BASE}/bin
CONFIGURE_ENV+=		LDFLAGS=-pthread CXXFLAGS="${CXXFLAGS} -pthread"
MAKE_ARGS+=		-j2

USE_KDELIBS_VER=3

.include <bsd.port.mk>

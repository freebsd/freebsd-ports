# New ports collection makefile for:	qtella
# Date created:				Sunday September 2nd, 2001
# Whom:					Jonathan Belson (jon@witchspace.com)
#
# $FreeBSD$
#

PORTNAME=		qtella
PORTVERSION=		0.4.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qtella

MAINTAINER=		jon@witchspace.com

USE_KDELIBS_VER=	2
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ARGS+=	--with-qt-dir=${X11BASE} --with-qt-moc=${X11BASE}/bin
CONFIGURE_ENV+=		LDFLAGS=-pthread CXXFLAGS="${CXXFLAGS} -pthread"
MAKE_ENV+=		MOC=${X11BASE}/bin/moc2
MAKE_ARGS+=		-j2

pre-patch:
	@${PERL} -pi.orig -e 's|/moc(\W)|/moc2\1|g' \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>

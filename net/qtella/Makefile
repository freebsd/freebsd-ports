# New ports collection makefile for:	qtella
# Date created:				Sunday September 2nd, 2001
# Whom:					Jonathan Belson (jon@witchspace.com)
#
# $FreeBSD$
#

PORTNAME=		qtella
PORTVERSION=		0.2.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qtella

MAINTAINER=		jon@witchspace.com

USE_KDELIBS_VER=	2
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ARGS+=	--with-qt-dir=${X11BASE} --with-qt-moc=${X11BASE}/bin
MAKE_ENV+=		MOC=${X11BASE}/bin/moc2

pre-patch:
	@${PERL} -pi -e 's|stdint.h|inttypes.h|g' ${WRKSRC}/include/* ${WRKSRC}/src/Servent.cc \
			${WRKSRC}/src/SearchViewItem.cc ${WRKSRC}/src/SharedViewItem.cc

post-install:
	strip ${PREFIX}/bin/qtella

.include <bsd.port.mk>

# New ports collection makefile for:	Krn
# Date created:				Sun Apr 16 14:19:19 PDT 2000
# Whom:					adsharma@sharmas.dhs.org
#
# $FreeBSD$
#

PORTNAME=	krn
PORTVERSION=	0.6.11
CATEGORIES=	news kde
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/krn/ \
		http://download.sourceforge.net/krn/

MAINTAINER=	adsharma@sharmas.dhs.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		uu.1:${PORTSDIR}/converters/uulib \
		mimelib.2:${PORTSDIR}/converters/kdesupport11

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/X11/qt

.include <bsd.port.mk>

# New ports collection makefile for:	xc-mail
# Date created:		2000-10-01
# Whom:			Trevor Johnson <trevor@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xc-mail
PORTVERSION=	1.3
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://js.zet.net/XCmail/download/ \
		ftp://trier.linux.de/pub/XCmail/ \
		ftp://ftp.myth.co.uk/pub/mirrors/xcmail/

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	Xclasses.1:${PORTSDIR}/x11-toolkits/xclasses
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	\
		--includedir=${X11BASE}/include/ \
		--libdir=${X11BASE}/lib/ \
		--x-includes=${X11BASE}/include/ \
		--x-libraries=${X11BASE}/lib/

CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib" \
		LIBS="-L${X11BASE}/lib"

.include <bsd.port.mk>

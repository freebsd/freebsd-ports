# New ports collection makefile for:	xc-mail
# Date created:		2000-10-01
# Whom:			Trevor Johnson <trevor@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xc-mail
PORTVERSION=	20001001 # from CVS
CATEGORIES=	mail
MASTER_SITES=	http://people.freebsd.org/~trevor/

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	Xclasses.1:${PORTSDIR}/x11-toolkits/xclasses

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS= \
		--includedir=${X11BASE}/include/ \
		--libdir=${X11BASE}/lib/ \
		--x-includes=${X11BASE}/include/ \
		--x-libraries=${X11BASE}/lib/

CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib" \
		LIBS="-L${X11BASE}/lib"

.include <bsd.port.mk>

# New ports collection makefile for:		xdelta
# Version required:				1.0.2
# Date created:					Sun May  4 21:40:06 CDT 1997
# Whom:						jmacd
#
# $FreeBSD$
#

DISTNAME=	xdelta-1.0.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=	jmacd@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS=-L${LOCALBASE}/lib \
		GLIB_CONFIG="${GLIB_CONFIG}"

MAN1=           xdelta.1

.include <bsd.port.mk>

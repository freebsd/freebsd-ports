# New ports collection makefile for:	gmime2
# Date created:				16 Apr 2001
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	2.0.8
CATEGORIES=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Library (written in C) for parsing and creating messages using MIME

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv
CONFLICTS=	gmime-0.*

USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_GNOME=	glib20
USE_LIBTOOL=	YES
CONFIGURE_ARGS+=	--with-libiconv=${LOCALBASE}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

INSTALLS_SHLIB=		YES

pre-configure:
.if exists(${X11BASE}/lib/libgmime.so)
	@${ECHO} ""
	@${ECHO} "You have gmime-1.x installed"
	@${ECHO} "Please deinstall gmime-1.x before installing this port"
	@${ECHO} ""
	@${FALSE}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	gmime2
# Date created:				16 Apr 2001
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	2.1.3
CATEGORIES=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/v2.1/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Library (written in C) for parsing and creating messages using MIME

CONFLICTS=	gmime-1.0.*

USE_ICONV=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 lthack
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libiconv=${LOCALBASE}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
INSTALLS_SHLIB=		yes

LATEST_LINK=	gmime2

pre-configure:
.if exists(${X11BASE}/lib/libgmime.so)
	@${ECHO} ""
	@${ECHO} "You have gmime-1.x installed"
	@${ECHO} "Please deinstall gmime-1.x before installing this port"
	@${ECHO} ""
	@${FALSE}
.endif

.include <bsd.port.mk>

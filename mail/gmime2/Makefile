# New ports collection makefile for:	gmime2
# Date created:				16 Apr 2001
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Library (written in C) for parsing and creating messages using MIME

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

CONFLICTS=	gmime-1.0.*

USE_SIZE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_LIBTOOL=	yes
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

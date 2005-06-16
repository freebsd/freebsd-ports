# New ports collection makefile for:	gmime2
# Date created:				16 Apr 2001
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	2.1.15
CATEGORIES=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/v2.1/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Library (written in C) for parsing and creating messages using MIME

CONFLICTS=	gmime-1.0.*

USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget glib20
USE_LIBTOOL_VER=15
CONFIGURE_ARGS+=	--with-libiconv=${LOCALBASE} \
			--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
			LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=		yes

LATEST_LINK=	gmime2

.include <bsd.port.mk>

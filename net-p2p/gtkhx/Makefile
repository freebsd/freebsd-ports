# New ports collection makefile for:   gtkhx
# Date created:        9 February 2002
# Whom:                Josh Elsasser <jre@vineyard.net>
#
# $FreeBSD$
#

PORTNAME=	gtkhx
PORTVERSION=	0.9.3
PORTREVISION=	6
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkhx

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ version of Hx, a UNIX Hotline Client

USE_XLIB=	yes
USE_GNOME=	gdkpixbuf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PREFIX}

MAN1=		gtkhx.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	pinfo
# Date created:		19 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pinfo
PORTVERSION=	0.6.9
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1502/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses based, lynx style info documentation browser

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-readline \
		--with-localedir=${PREFIX}/share/locale

MAN1=		pinfo.1
INFO=		pinfo

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>

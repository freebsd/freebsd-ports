# Created by: Marco Molteni <molter@gufi.org>
# $FreeBSD$

PORTNAME=	bookmarkbridge
PORTVERSION=	0.76
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Synchronize bookmarks between multiple browsers

USES=		gmake perl5 pkgconfig shebangfix
SHEBANG_FILES=	bookmarkbridge/docs/autodocs.pl
USE_PERL5=	yes
USE_XORG=	x11 ice xext
USE_QT4=	corelib gui qt3support moc_build rcc_build uic_build
USE_GNOME=	libxml2
USE_AUTOTOOLS=	aclocal automake autoconf
AUTOMAKE_ARGS=	--add-missing

DESKTOP_ENTRIES="BookmarkBridge" "" "" "${PORTNAME}" "Qt;Network;" ""

.include <bsd.port.mk>

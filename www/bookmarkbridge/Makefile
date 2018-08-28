# Created by: Marco Molteni <molter@gufi.org>
# $FreeBSD$

PORTNAME=	bookmarkbridge
PORTVERSION=	0.76
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Synchronize bookmarks between multiple browsers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Unmaintained. Unlikely to work correctly with modern browsers
EXPIRATION_DATE=	2018-09-15

USES=		autoreconf gmake perl5 pkgconfig qt:4 shebangfix
USE_CXXSTD=	gnu++98
SHEBANG_FILES=	bookmarkbridge/docs/autodocs.pl
USE_XORG=	x11 ice xext
USE_QT=		corelib gui qt3support moc_build rcc_build uic_build
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="BookmarkBridge" "" "" "${PORTNAME}" "Qt;Network;" ""

.include <bsd.port.mk>

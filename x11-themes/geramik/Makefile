# New ports collection makefile for:   geramik
# Date created:                04 January 2003
# Whom:                        hdc <haesu@towardex.com>
#
# $FreeBSD$
#

PORTNAME=	geramik
PORTVERSION=	0.26
PORTREVISION=	4
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kde-look.org/content/files/ \
		http://distfiles.towardex.com/
DISTNAME=	3952-Geramik-${PORTVERSION}

MAINTAINER=	haesu@TowardEX.com
COMMENT=	A Keramik KDE styled theme for GTK

RUN_DEPENDS=	${X11BASE}/lib/gtk/themes/engines/libqtpixmap.so:${PORTSDIR}/x11-toolkits/qtpixmap

WRKSRC=		${WRKDIR}/Geramik-${PORTVERSION}

USE_LIBTOOL_VER=13
USE_X_PREFIX=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>

# New ports collection makefile for:   geramik
# Date created:                04 January 2003
# Whom:                        hdc <haesu@towardex.com>
#
# $FreeBSD$
#

PORTNAME=	geramik
PORTVERSION=	0.27
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/ \
		http://distfiles.towardex.com/
DISTNAME=	3952-Geramik-${PORTVERSION}

MAINTAINER=	haesu@TowardEX.com
COMMENT=	A Keramik KDE styled theme for GTK

DEPRECATED=	Depends on x11-toolkits/qtpixmap, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libqtpixmap.so:${PORTSDIR}/x11-toolkits/qtpixmap

WRKSRC=		${WRKDIR}/Geramik-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

.include <bsd.port.mk>

# New ports collection makefile for:   geramik
# Date created:                04 January 2003
# Whom:                        hdc <haesu@towardex.com>
#
# $FreeBSD$
#

PORTNAME=	geramik
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.kde-look.org/content/files/ \
		http://distfiles.towardex.com/
DISTNAME=	3952-Geramik-${PORTVERSION}

MAINTAINER=	haesu@TowardEX.com

WRKSRC=		${WRKDIR}/Geramik-${PORTVERSION}

USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes

.if exists(${X11BASE}/libdata/pkgconfig/gtk+-2.0.pc) || defined(WITH_GTK2)
LIB_DEPENDS+=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20
PLIST_SUB+=	GTK2="" GTK2_VERSION="2.0.0"
.else
PLIST_SUB+=	GTK2="@comment "
.endif

.include <bsd.port.mk>

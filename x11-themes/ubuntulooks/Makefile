# New ports collection makefile for:	ubuntulooks
# Date created:		2006-04-09
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ubuntulooks
PORTVERSION=	0.9.9
CATEGORIES=	x11-themes
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/main/u/ubuntulooks/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	pneumann@gmail.com
COMMENT=	GTK+ 2.x engine from Ubuntu Dapper

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	libquicktime
# Date Created:			Jul 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libquicktime
PORTVERSION=	0.9.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		dv:${PORTSDIR}/graphics/libdv

USE_GNOMENG=	yes
USE_GNOME=	glib12 gtk12
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lstdc++"

MAN1=	lqtplay.1

.include <bsd.port.mk>

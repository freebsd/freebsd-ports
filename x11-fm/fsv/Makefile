# New ports collection makefile for:   fsv
# Date created:        06 February 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fsv
PORTVERSION=	0.9
PORTREVISION=	6
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	3D filesystem visualizer

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_GETTEXT=	yes
USE_GL=		gl
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-GL-prefix=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-extract:
	-@${RM} ${WRKSRC}/lib/getopt*

.include <bsd.port.mk>

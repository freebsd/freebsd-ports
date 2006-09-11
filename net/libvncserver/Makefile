# ex:ts=8
# Ports collection makefile for:	libvncserver
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libvncserver
PORTVERSION=	0.8.2
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	LibVNCServer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide an easy API to write one's own vnc server

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-x

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|x11vnc||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/rfb/default8x16.h ${PREFIX}/include/rfb

.include <bsd.port.mk>

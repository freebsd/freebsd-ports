# ex:ts=8
# Ports collection makefile for:	libvncserver
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libvncserver
PORTVERSION=	0.6.2
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	x11vnc-${PORTVERSION}

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	Provide an easy API to write one's own vnc server

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

.ifndef(WITHOUT_X11)
USE_XLIB=       yes
PLIST_SUB+=     X11=""
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=     X11="@comment "
.endif

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|" ${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/include/rfb
	${INSTALL_DATA} ${WRKSRC}/rfb/*.h ${PREFIX}/include/rfb
	${INSTALL_DATA} ${WRKSRC}/libvncserver/*.a ${PREFIX}/lib

.include <bsd.port.mk>

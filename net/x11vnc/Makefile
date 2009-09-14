# New ports collection makefile for:	x11vnc
# Date created:				7 June 2005
# Whom:					Loren M. Lang
#
# $FreeBSD$
#

PORTNAME=	x11vnc
PORTVERSION=	0.9.7
CATEGORIES=	net
MASTER_SITES=	SF/libvncserver/${PORTNAME}/${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	VNC server for use with real X displays

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		dbus:${PORTSDIR}/devel/dbus \
		avahi-common.3:${PORTSDIR}/net/avahi-app

USE_GNOME=	gnometarget
USE_XORG=	x11 xdamage xfixes xrandr xinerama xext xtst xau xrender xdmcp recordproto
# Sets LDFLAGS and adds to CONFIGURE_ENV, therefore we set LDFLAGS
LDFLAGS+=	-L${LOCALBASE}/lib
USE_OPENSSL=	yes
USE_ICONV=	yes
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		x11vnc.1
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README README.LibVNCServer TODO

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

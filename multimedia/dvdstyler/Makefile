# New ports collection makefile for:	dvdstyler
# Date created:		2004-07-30
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	dvdstyler
DISTVERSION=	1.5.1_2
PORTREVISION=	6
PORTEPOCH=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.5.1
DISTNAME=	DVDStyler-${DISTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	WXGTK2 front end to dvd recoding and authoring programs

BUILD_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		jpegtopnm:${PORTSDIR}/graphics/netpbm \
		mpgtx:${PORTSDIR}/multimedia/mpgtx \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
RUN_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		jpegtopnm:${PORTSDIR}/graphics/netpbm \
		mpgtx:${PORTSDIR}/multimedia/mpgtx \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools

USE_WX=		2.6
WX_COMPS=	wx svg
WX_CONF_ARGS=	absolute
USE_GMAKE=	yes
USE_GNOME=	gnometarget desktopfileutils
WANT_GNOME=	yes
USE_GETTEXT=	yes
USE_CDRTOOLS=	yes	# dvdstyler needs mkisofs
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
.endif

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/cd0
.endif

pre-everything::
.if !defined(WITH_DVD_DEVICE)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|g' \
		${WRKSRC}/src/BurnDlg.cpp ${WRKSRC}/src/Config.h
	@${REINPLACE_CMD} -e 's|gnome-config|disable-config|g ;  \
		s|kde-config|disable-config|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/data/dvdstyler.desktop \
		${PREFIX}/share/applications/
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/src/rc/dvdstyler.png \
		${PREFIX}/share/pixmaps/
	@-update-desktop-database

.include <bsd.port.post.mk>

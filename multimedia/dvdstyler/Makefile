# New ports collection makefile for:	dvdstyler
# Date created:		2004-07-30
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	dvdstyler
PORTVERSION=	1.06
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dvdstyler
DISTNAME=	DVDStyler-${PORTVERSION}

MAINTAINER=	ahze@ahze.net
COMMENT=	WXGTK2 front end to dvd recoding and authoring programs

BUILD_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpgcat:${PORTSDIR}/multimedia/mpgtx \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm \
		lavfile-1.6.2:${PORTSDIR}/multimedia/mjpegtools \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=15
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-wx-config=wxgtk2-2.4-config
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif
.endif

pre-everything::
.if !defined(WITH_DVD_DEVICE)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> Define WITH_OPTIMIZED_CFLAGS to enable optimized cflags"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$prefix/dvdstyler|${DATADIR}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|mp2 AUTHORS COPYING INSTALL README ChangeLog|mp2|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/Config.h
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O3||' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>

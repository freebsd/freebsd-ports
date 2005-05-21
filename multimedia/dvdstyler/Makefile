# New ports collection makefile for:	dvdstyler
# Date created:		2004-07-30
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	dvdstyler
PORTVERSION=	1.4
PORTEPOCH=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dvdstyler
DISTNAME=	DVDStyler-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	WXGTK2 front end to dvd recoding and authoring programs

BUILD_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpgcat:${PORTSDIR}/multimedia/mpgtx \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm \
		lavfile-1.6.2:${PORTSDIR}/multimedia/mjpegtools \
		wx_base-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26
RUN_DEPENDS=	${BUILD_DEPENDS}
#RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine

DVDSTYLER_ICON=	${DATADIR}/rc/dvdstyler.png
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=15
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-wx-config=wxgtk2-2.6-config
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	AUTHORS COPYING INSTALL ChangeLog README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build.
.endif

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
	@${SED} -e 's|%%COMMENT%%|${COMMENT}|; \
		s|%%DVDSTYLER_ICON%%|${DVDSTYLER_ICON}|' \
		< ${FILESDIR}/dvdstyler.desktop.in > ${WRKDIR}/dvdstyler.desktop
	@${REINPLACE_CMD} -e 's|$$prefix/dvdstyler|${DATADIR}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@datadir@/docs/@PACKAGE@|${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/Config.h
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O3||' \
		${WRKSRC}/configure
.endif

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/dvdstyler.desktop ${PREFIX}/share/applications

.include <bsd.port.post.mk>

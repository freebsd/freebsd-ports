# New ports collection makefile for:	camserv
# Date created:         Sat 22 July 2000
# Whom:                 Chuck Hein <chein@freebsd.org> & Jim Overholt <overholt@isdw.net>
#
# $FreeBSD$
#

PORTNAME=	camserv
PORTVERSION=	0.5.1
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cserv

MAINTAINER=	q@uni.de
COMMENT=	Camserv is a free program to do streaming video via the web

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		Imlib2.2:${PORTSDIR}/graphics/imlib2 \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		freetype.9:${PORTSDIR}/print/freetype2 \
		ltdl.4:${PORTSDIR}/devel/libltdl

ONLY_FOR_ARCHS=	i386 alpha

USE_X_LIB=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=253

#CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
		-I${X11BASE}/include/gtk12 -I${X11BASE}/include/gdk-pixbuf-1.0 \
		-I${LOCALBASE}/include/glib12" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--enable-static=no

.if exists(/usr/include/dev/bktr/ioctl_bt848.h)
post-patch:
	${REINPLACE_CMD} -e 's#machine/\(ioctl_bt848.h\)#dev/bktr/\1#' \
		${WRKSRC}/camserv/video_fbsd_bttv.c \
		${WRKSRC}/configure.in
.endif

.if exists(/usr/include/machine/ioctl_bt848.h) || \
	exists(/usr/include/dev/bktr/ioctl_bt848.h)
PLIST_SUB+=	BKTR=""
.else
PLIST_SUB+=	BKTR="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/javascript.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>

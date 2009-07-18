# New ports collection makefile for:	camserv
# Date created:         Sat 22 July 2000
# Whom:                 Chuck Hein <chein@freebsd.org> & Jim Overholt <overholt@isdw.net>
#
# $FreeBSD$
#

PORTNAME=	camserv
PORTVERSION=	0.5.1
PORTREVISION=	10
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cserv

MAINTAINER=	uspoerlein@gmail.com
COMMENT=	Camserv is a free program to do streaming video via the web

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		freetype.9:${PORTSDIR}/print/freetype2

ONLY_FOR_ARCHS=	i386 alpha

USE_AUTOTOOLS=	autoconf:262 libtool:15 libltdl:15
USE_EFL=	imlib2

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/gtk12 \
		-I${LOCALBASE}/include/gdk-pixbuf-1.0 \
		-I${LOCALBASE}/include/glib12" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if exists(/usr/include/dev/bktr/ioctl_bt848.h)
post-patch:
	@${REINPLACE_CMD} -e 's#machine/\(ioctl_bt848.h\)#dev/bktr/\1#' \
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

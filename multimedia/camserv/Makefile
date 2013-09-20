# Created by: Chuck Hein <chein@FreeBSD.org> & Jim Overholt <overholt@isdw.net>
# $FreeBSD$

PORTNAME=	camserv
PORTVERSION=	0.5.1
PORTREVISION=	16
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/cserv/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Camserv is a free program to do streaming video via the web

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		freetype.9:${PORTSDIR}/print/freetype2

ONLY_FOR_ARCHS=	i386 alpha

USE_AUTOTOOLS=	autoconf libtool libltdl
USE_EFL=	imlib2

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/gtk12 \
		-I${LOCALBASE}/include/gdk-pixbuf-1.0 \
		-I${LOCALBASE}/include/glib12
LDFLAGS+=	-L${LOCALBASE}/lib

.if exists(/usr/include/dev/bktr/ioctl_bt848.h)
NO_STAGE=	yes
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

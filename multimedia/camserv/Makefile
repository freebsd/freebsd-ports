# Created by: Chuck Hein <chein@FreeBSD.org> & Jim Overholt <overholt@isdw.net>
# $FreeBSD$

PORTNAME=	camserv
PORTVERSION=	0.5.1
PORTREVISION=	18
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/cserv/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free program to do streaming video via the web

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

USES=		libtool
USE_AUTOTOOLS=	autoconf libltdl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	IMLIB2 PIXBUF V4L DOCS
OPTIONS_DEFAULT=IMLIB2
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMLIB2}
USE_EFL+=	imlib2
.else
CONFIGURE_ENV+=	ac_cv_path_IMLIB2_CONFIG=no
.endif

.if ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf
.else
CONFIGURE_ENV+=	ac_cv_path_GDKPIXBUF_CONFIG=no
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=	v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat
.else
CONFIGURE_ENV=	ac_cv_header_linux_videodev_h=no
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^camserv_DEP/s|=.*|=|' ${WRKSRC}/camserv/Makefile.in
.for i in common/Makefile.in relay/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^CFLAGS/s|-g||' ${WRKSRC}/${i}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README javascript.txt \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

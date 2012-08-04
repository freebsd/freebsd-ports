# New ports collection Makefile for:	fox17
# Date created:				23 August 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.7.33
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.fox-toolkit.org/pub/ \
   		ftp://ftp.fox-toolkit.org/pub/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit -- devel version

LIB_DEPENDS=	Xft:${PORTSDIR}/x11-fonts/libXft

CONFLICTS=	fox-1.4.* fox-1.6.*

OPTIONS=	JPEG	"Enable JPEG support" ON \
		PNG	"Enable PNG support" ON \
		TIFF	"Enable TIFF support" ON \
		WEBP	"Enable WebP support" ON

LATEST_LINK=	fox17

MAJORVER=	${PORTVERSION:R}
PLIST_SUB+=	MAJORVER=${MAJORVER}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${MAJORVER}

USE_GCC=	4.4+
USE_GL=		glut
USE_XORG=	sm
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl=yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		reswrap.1 shutterbug.1 adie.1 PathFinder.1 calculator.1 \
		ControlPanel.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=--disable-jpeg
.else
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=--disable-png
.else
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.endif

.if defined(WITHOUT_TIFF)
CONFIGURE_ARGS+=--disable-tiff
.else
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
.endif

.if defined(WITHOUT_WEBP)
CONFIGURE_ARGS+=--disable-webp
.else
LIB_DEPENDS+=	webp:${PORTSDIR}/graphics/webp
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not link on powerpc
.endif

post-patch:
	${REINPLACE_CMD} -e '/^Libs:/s|$$| ${PTHREAD_LIBS}|; s|"||g' ${WRKSRC}/fox17.pc.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^SUBDIRS/s/ doc//' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>

# New ports collection Makefile for:	fox17
# Date created:				23 August 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.7.35
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.fox-toolkit.org/pub/ \
   		ftp://ftp.fox-toolkit.org/pub/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit -- devel version

LIB_DEPENDS=	Xft:${PORTSDIR}/x11-fonts/libXft

OPTIONS_DEFINE=	JPEG PNG TIFF WEBP
OPTIONS_DEFAULT=JPEG PNG TIFF WEBP

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
CONFIGURE_ARGS=	--with-opengl=yes \
		--bindir=${PREFIX}/bin/${PORTNAME}-${MAJORVER}

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		reswrap-17.1 shutterbug-17.1 adie-17.1 PathFinder-17.1 \
		calculator-17.1 ControlPanel-17.1
.for man1 in ${MAN1}
MAN_REPLACE+=	s|${man1:S/-17//}|${man1}|;
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=--disable-jpeg
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=--disable-png
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
.else
CONFIGURE_ARGS+=--disable-tiff
.endif

.if ${PORT_OPTIONS:MWEBP}
LIB_DEPENDS+=	webp:${PORTSDIR}/graphics/webp
.else
CONFIGURE_ARGS+=--disable-webp
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not link on powerpc
.endif

post-patch:
	for f in ${MAN1}; do \
	    old=$$(echo $$f | sed -e 's|-17||'); \
	    dir=$$(dirname $$(find ${WRKSRC} -name $$old)); \
	    mv $$dir/$$old $$dir/$$f; \
	done
	${FIND} ${WRKSRC} -name Makefile.am -o -name Makefile.in | ${XARGS} \
	    ${REINPLACE_CMD} -i '' -e '${MAN_REPLACE}'
	${REINPLACE_CMD} -e '/^Libs:/s|$$| ${PTHREAD_LIBS}|; s|"||g' ${WRKSRC}/fox17.pc.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^SUBDIRS/s/ doc//' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>

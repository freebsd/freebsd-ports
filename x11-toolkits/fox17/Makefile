# New ports collection Makefile for:	fox17
# Date created:				23 August 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.7.30
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.fox-toolkit.org/ftp/ \
		ftp://ftp.fox-toolkit.org/pub/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit -- devel version

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

CONFLICTS=	fox-1.4.* fox-1.6.*

LATEST_LINK=	fox17

MAJORVER=	${PORTVERSION:R}
PLIST_SUB+=	MAJORVER=${MAJORVER}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${MAJORVER}

USE_GL=		glut
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl=yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		reswrap.1 shutterbug.1 adie.1 PathFinder.1 calculator.1 \
		ControlPanel.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && ${OSVERSION} < 900000
BROKEN=		does not build on amd64
.endif

post-patch:
	${REINPLACE_CMD} -e '/^Libs:/s|$$| ${PTHREAD_LIBS}|' ${WRKSRC}/fox17.pc.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^SUBDIRS/s/ doc//' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>

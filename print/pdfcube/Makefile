# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdfcube
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://code.100allora.it/releases/pdfcube/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	An OpenGL presentation viewer on a spinning cube

LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext \
		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		libboost_program_options.so:${PORTSDIR}/devel/boost-libs

USES=		pkgconfig
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include

PLIST_FILES=	bin/pdfcube

post-patch:
	${REINPLACE_CMD} -e \
		's|BOOSTLIBDIR/libboost_program_options\*\.{so,a}\*|BOOSTLIBDIR/libboost_program_options.so|' \
		${WRKSRC}/configure

.include <bsd.port.mk>

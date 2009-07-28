# New ports collection makefile for:	pdfcube
# Date created:		Apr. 20, 2007
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdfcube
PORTVERSION=	0.0.3
CATEGORIES=	print
MASTER_SITES=	http://code.100allora.it/releases/pdfcube/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	An OpenGL presentation viewer on a spinning cube

LIB_DEPENDS=	gtkglext:${PORTSDIR}/x11-toolkits/gtkglext \
		poppler-glib:${PORTSDIR}/graphics/poppler-gtk \
		boost_program_options:${PORTSDIR}/devel/boost-libs

USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include

PLIST_FILES=	bin/pdfcube

post-patch:
	${REINPLACE_CMD} -e \
		's|BOOSTLIBDIR/libboost_program_options\*\.{so,a}\*|BOOSTLIBDIR/libboost_program_options.so|' \
		${WRKSRC}/configure

.include <bsd.port.mk>

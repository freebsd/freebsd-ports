# Created by: ijliao
# $FreeBSD$

PORTNAME=	gtkmathview
PORTVERSION=	0.8.0
PORTREVISION=	9
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://helm.cs.unibo.it/mml-widget/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK Widget to Render MathML Documents

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	libpopt.so:devel/popt \
		libt1.so:devel/t1lib \
		libgmetadom_gdome_cpp_smart.so:textproc/gmetadom

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang gmake gnome libtool localbase:ldflags \
		pathfix pkgconfig
USE_GNOME=	gtk20 libxml2 pangox-compat
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
CXXFLAGS_gcc=	-Wno-error=narrowing

post-patch:
	@${REINPLACE_CMD} '/-lstdc++/d' ${WRKSRC}/src/Makefile.in \
		${WRKSRC}/src/view/Makefile.in ${WRKSRC}/viewer/Makefile.in
	@${REINPLACE_CMD} '/^mathmlps_LDADD =/s|=|= ../src/libmathview.la|' \
		${WRKSRC}/mathmlps/Makefile.in
	@${REINPLACE_CMD} '/^mathmlsvg_LDADD =/s|=|= $$(XML_LIBS) ../src/libmathview.la|' \
		${WRKSRC}/mathmlsvg/Makefile.in
	@${REINPLACE_CMD} '/^test_rendering_LDADD =/s|=|= ../src/libmathview.la|' \
		${WRKSRC}/viewer/Makefile.in

.include <bsd.port.mk>

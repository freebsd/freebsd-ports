# Created by: ijliao
# $FreeBSD$

PORTNAME=	gtkmathview
PORTVERSION=	0.8.0
PORTREVISION=	8
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://helm.cs.unibo.it/mml-widget/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK Widget to Render MathML Documents

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libt1.so:${PORTSDIR}/devel/t1lib \
		libgmetadom_gdome_cpp_smart.so:${PORTSDIR}/textproc/gmetadom

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	gtk20 libxml2 pangox-compat
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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

# Created by: ijliao
# $FreeBSD$

PORTNAME=	gtkdatabox
PORTVERSION=	0.9.2.0
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+2 widget to display large amounts of numerical data

LICENSE=	LGPL21

OPTIONS_DEFINE=	GLADE GLADEUI DOCS EXAMPLES
GLADE_DESC=	Enable libglade2 support
GLADEUI_DESC=	Enable glade3 support

USES=		libtool pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${PREFIX}/include/${PORTNAME}" \
		--with-html-dir="${PREFIX}/share/doc"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_SUB=yes

PORTDOCS=	*
PORTEXAMPLES=	*

GLADE_USE=	GNOME=libglade2
GLADE_CONFIGURE_ENABLE=	libglade

GLADEUI_LIB_DEPENDS=	libgladeui-1.so:${PORTSDIR}/devel/glade3
GLADEUI_CONFIGURE_ENABLE=	glade

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIR/s|examples||' ${WRKSRC}/Makefile.in
.for dir in examples gtk
	@${REINPLACE_CMD} -e \
		'/-O2/d ; \
		 /DISABLE_DEPRECATED/d' ${WRKSRC}/${dir}/Makefile.in
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} api ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} *.c ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

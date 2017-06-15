# Created by: ijliao
# $FreeBSD$

PORTNAME=	gtkdatabox
PORTVERSION=	0.9.2.0
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+2 widget to display large amounts of numerical data

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${PREFIX}/include/${PORTNAME}" \
		--with-html-dir="${PREFIX}/share/doc"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	GLADE GLADEUI DOCS EXAMPLES
OPTIONS_SUB=	yes

GLADE_DESC=	Enable libglade2 support
GLADE_USE=	GNOME=libglade2
GLADE_CONFIGURE_ENABLE=	libglade
GLADEUI_DESC=	Enable glade3 support
GLADEUI_LIB_DEPENDS=	libgladeui-1.so:devel/glade3
GLADEUI_CONFIGURE_ENABLE=	glade

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIR/s|examples||' ${WRKSRC}/Makefile.in
.for dir in examples gtk
	@${REINPLACE_CMD} -e \
		'/-O2/d ; \
		 /DISABLE_DEPRECATED/d' ${WRKSRC}/${dir}/Makefile.in
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} api ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

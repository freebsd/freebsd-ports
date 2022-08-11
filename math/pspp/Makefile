PORTNAME=	pspp
PORTVERSION=	1.6.1
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for statistical analysis of sampled data

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Text-Diff>=0:textproc/p5-Text-Diff \
		texinfo>0:print/texinfo
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libpango-1.0.so:x11-toolkits/pango \
		libgslcblas.so:math/gsl

USES=		cpe charsetfix gettext-tools gmake gnome iconv localbase \
		libtool perl5 pkgconfig python:3.7+,build readline

CPE_VENDOR=	gnu
USE_GNOME=	libxml2
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON3=${PYTHON_CMD}
MAKE_ARGS=	MAKEINFO="${LOCALBASE}/bin/makeinfo" \
		XMLLINT="${LOCALBASE}/bin/xmllint"
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

LDFLAGS+=	-L${LOCALBASE}/lib -lxml2

INFO=		pspp pspp-dev
PLIST_SUB=	VERSION="${PORTVERSION}"
PORTDOCS=	AUTHORS ChangeLog NEWS ONEWS README THANKS
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES GUI NLS PGSQL
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_LIB_DEPENDS=	libgladeui-2.so:devel/glade \
			libspread-sheet-widget.so:devel/spread-sheet-widget
GUI_USES=		desktop-file-utils shared-mime-info
GUI_USE=		gnome=cairo,gtk30,gtksourceview3,pango pkgconfig
GUI_CONFIGURE_WITH=	cairo gui
GUI_INSTALL_TARGET=	install-icons install-ext-icons

NLS_BUILD_DEPENDS=	appstream-glib>0:devel/appstream-glib
NLS_USES=		gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls
NLS_MAKE_ARGS_OFF=	POFILES=""

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	libpq

pre-configure-GUI-off:
	${REINPLACE_CMD} -e '/language=Glade/d;/j src\/ui\/gui/d'	\
			${WRKSRC}/Makefile.in

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \
		"${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

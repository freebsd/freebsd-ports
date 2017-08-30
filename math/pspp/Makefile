# Created by: Andrew L. Neporada <andrew@chg.ru>
# $FreeBSD$

PORTNAME=	pspp
PORTVERSION=	1.0.1
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Program for statistical analysis of sampled data

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	texinfo>0:print/texinfo
LIB_DEPENDS=	libgslcblas.so:math/gsl

USES=		charsetfix gmake iconv localbase libtool perl5 pkgconfig readline
USE_GNOME=	libxml2
USE_PERL5=	build
GNU_CONFIGURE=	yes
MAKE_ARGS=	MAKEINFO="${LOCALBASE}/bin/makeinfo" \
		XMLLINT="${LOCALBASE}/bin/xmllint"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog NEWS ONEWS README THANKS TODO
PORTEXAMPLES=	*
INFO=		pspp pspp-dev

OPTIONS_DEFINE=		DOCS EXAMPLES GUI NLS PGSQL
OPTIONS_SUB=		yes

GUI_LIB_DEPENDS=	libgladeui-2.so:devel/glade
GUI_RUN_DEPENDS=	yelp:x11/yelp
GUI_USES=		desktop-file-utils
GUI_USE=		gnome=gtk30,gtksourceview3
GUI_VARS=		INSTALLS_ICONS=yes
GUI_CONFIGURE_WITH=	cairo gui gui-tools
GUI_INSTALL_TARGET=	install-icons install-ext-icons

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_MAKE_ARGS_OFF=	POFILES=""

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	libpq

post-patch:
	@${REINPLACE_CMD} -e \
		's|: $$(INSTALL_DATA_HOOKS)|:|g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/pspp-mode.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp

post-install-GUI-on:
	${RM} -r ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/mimetypes

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \
		"${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

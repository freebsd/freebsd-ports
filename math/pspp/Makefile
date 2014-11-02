# Created by: Andrew L. Neporada <andrew@chg.ru>
# $FreeBSD$

PORTNAME=	pspp
PORTVERSION=	0.8.4
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for statistical analysis of sampled data

LICENSE=	GPLv3

BUILD_DEPENDS=	texinfo>0:${PORTSDIR}/print/texinfo
LIB_DEPENDS=	libplot.so:${PORTSDIR}/graphics/plotutils \
		libgslcblas.so:${PORTSDIR}/math/gsl

USES=		charsetfix gmake iconv libtool perl5 pkgconfig readline
USE_GNOME=	libxml2
USE_PERL5=	build
GNU_CONFIGURE=	yes
MAKE_ARGS=	MAKEINFO="${LOCALBASE}/bin/makeinfo" \
		XMLLINT="${LOCALBASE}/bin/xmllint"
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

INFO=		pspp pspp-dev

OPTIONS_DEFINE=		DOCS GUI NLS PGSQL
OPTIONS_SUB=		yes

GUI_LIB_DEPENDS=	libgladeui-1.so:${PORTSDIR}/devel/glade3
GUI_RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp
GUI_USES=		desktop-file-utils
GUI_USE=		gnome=gtksourceview2,libglade2
GUI_CONFIGURE_WITH=	cairo gui gui-tools
GUI_INSTALL_TARGET=	install-strip install-icons install-ext-icons
GUI_INSTALL_TARGET_OFF=	install-strip
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	libpq

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
INSTALLS_ICONS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|: $$(INSTALL_DATA_HOOKS)|:|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

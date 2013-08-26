# Created by: Andrew L. Neporada <andrew@chg.ru>
# $FreeBSD$

PORTNAME=	pspp
PORTVERSION=	0.6.2
PORTREVISION=	10
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Program for statistical analysis of sampled data

LIB_DEPENDS=	plot.4:${PORTSDIR}/graphics/plotutils \
		gslcblas:${PORTSDIR}/math/gsl

OPTIONS_DEFINE=	GUI PGSQL

USE_GNOME=	libxml2
USE_PERL5_BUILD=yes
USES=		iconv
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

INFO=		pspp pspp-dev

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	gladeui-1:${PORTSDIR}/devel/glade3
RUN_DEPENDS+=	yelp:${PORTSDIR}/x11/yelp
USE_GNOME+=	libglade2
CONFIGURE_ARGS+=	--with-gui-tools
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=	--without-gui
PLIST_SUB+=	GUI="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
.else
CONFIGURE_ARGS+=	--without-libpq
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^install-exec-am:/s|install-exec-local||' \
		${WRKSRC}/gl/Makefile.in
post-install:
	@${TOUCH} ${PREFIX}/lib/pspp/.keep_me

.include <bsd.port.mk>

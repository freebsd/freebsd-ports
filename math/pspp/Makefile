# New ports collection makefile for:   pspp
# Date created:                        22 Apr 2000
# Whom:                                Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	pspp
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Program for statistical analysis of sampled data

LIB_DEPENDS=	plot.4:${PORTSDIR}/graphics/plotutils \
		gslcblas.0:${PORTSDIR}/math/gsl

OPTIONS=	GUI "Build the PSPPIRE gui" off \
		PGSQL "Compile in PostgreSQL capability" off

USE_GNOME=	libxml2
USE_PERL5_BUILD=yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

INFO=		pspp pspp-dev

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_GUI)
LIB_DEPENDS+=	gladeui-1:${PORTSDIR}/devel/glade3
RUN_DEPENDS+=	yelp:${PORTSDIR}/x11/yelp
USE_GNOME+=	libglade2
CONFIGURE_ARGS+=	--with-gui-tools
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=	--without-gui
PLIST_SUB+=	GUI="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.else
CONFIGURE_ARGS+=	--without-libpq
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^install-exec-am:/s|install-exec-local||' \
		${WRKSRC}/gl/Makefile.in

post-install:
	@${TOUCH} ${PREFIX}/lib/pspp/.keep_me

.include <bsd.port.post.mk>

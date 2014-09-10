# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/www/epiphany-extensions/Makefile,v 1.140 2012/12/13 20:33:05 kwm Exp $

PORTNAME=	epiphany-extensions
PORTVERSION=	2.30.2
PORTREVISION=	7
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Set of add-ons for the Epiphany web browser

BUILD_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany

CONFLICTS=	epiphany-extensions-3.[0-9]*

USES=		gettext gmake pathfix libtool pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip

EPHY_EXTENSIONS=really-all
EPHY_VERSION=	${PORTVERSION:R}

PLIST_SUB=	VERSION=${EPHY_VERSION} EPHY_VERSION=${EPHY_VERSION}

OPTIONS_DEFINE=	OPENSP
OPENSP_DESC=	OpenSP SGML support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSP}
CONFIGURE_ARGS+=	--enable-opensp=yes
LIB_DEPENDS+=		libosp.so:${PORTSDIR}/textproc/opensp
.else
CONFIGURE_ARGS+=	--disable-opensp
.endif

CONFIGURE_ARGS+=--with-extensions="${EPHY_EXTENSIONS}"

post-patch:
	@${REINPLACE_CMD} -e 's|$$($$PKG_CONFIG --variable=extensionsdir epiphany-$$_epiphany_api_version)|${PREFIX}/lib/epiphany/${PORTVERSION:R}/extensions|g' \
		-e 's|$$($$PKG_CONFIG --variable=icondir epiphany-$$EPIPHANY_API_VERSION)|${PREFIX}/share/epiphany/icons|g' \
		-e 's|EPIPHANY_API_VERSION=2.29|EPIPHANY_API_VERSION=2.30|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>

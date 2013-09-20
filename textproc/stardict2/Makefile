# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	stardict
PORTVERSION=	2.4.8
PORTREVISION=	14
CATEGORIES=	textproc
MASTER_SITES=	SF
DIST_SUBDIR=	stardict

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Cross-platform and international dictionary written in Gtk2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix
USES=		gettext gmake pkgconfig
LATEST_LINK=	stardict2

OPTIONS_DEFINE=	GNOME
OPTIONS_DEFAULT=	GNOME

CONFLICTS=	stardict-3.[0-9]*

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	libgnomeui
GCONF_SCHEMAS=	stardict.schemas
INSTALLS_OMF=	yes
PLIST_SUB=	GNOME=""
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--disable-gnome-support --disable-schemas-install
PLIST_SUB=	GNOME="@comment not installed: "
.endif

MAN1=		stardict.1

post-patch:
# gcc 2.95 does not know std::string::clear()
	@${REINPLACE_CMD} -e 's|.clear()|.erase()|' \
		${WRKSRC}/src/docklet.cpp ${WRKSRC}/src/floatwin.cpp \
		${WRKSRC}/src/selection.cpp

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

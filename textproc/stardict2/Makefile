# Ports collection makefile for:	stardict2
# Date created:			13 April 2003
# Whom:				Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	stardict
PORTVERSION=	2.4.8
PORTREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	stardict

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	A cross-platform and international dictionary written in Gtk2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes
LATEST_LINK=	stardict2

OPTIONS=	GNOMEUI "GNOME support" On

CONFLICTS=	stardict-3.[0-9]*

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GNOMEUI)
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

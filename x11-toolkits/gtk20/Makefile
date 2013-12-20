# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtk20/Makefile,v 1.237 2013/03/04 17:44:38 kwm Exp $

PORTNAME=	gtk
PORTVERSION=	2.24.22
PORTREVISION?=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	2
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (previous stable version)

LICENSE=	LGPL20

USE_XZ=		yes

PORTSCOUT=	limitw:0,even

.if !defined(REFERENCE_PORT)

RUN_DEPENDS+=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		python:${PORTSDIR}/lang/python

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk pango gdkpixbuf2 introspection:build ltverhack \
		gtk-update-icon-cache
USES=		gettext gmake pathfix pkgconfig perl5
USE_PERL5=	build
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
CONFIGURE_ARGS=	--with-xinput=yes --enable-explicit-deps
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS DEBUG
OPTIONS_DEFAULT=CUPS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
CONFIGURE_ARGS+=--enable-cups=auto
PLIST_SUB+=	CUPS:=""
.else
CONFIGURE_ARGS+=--disable-cups
PLIST_SUB+=	CUPS:="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug=yes
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${GREP} -l lgmodule | \
		${XARGS} ${REINPLACE_CMD} -e 's|-lgmodule|@GMODULE_LIBS@|g'
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/locale|{datadir}/locale|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@LN_S@|${LN} -sf|' ${WRKSRC}/gtk/Makefile.in
	@${REINPLACE_CMD} -e 's|file,cups|file,cups,lpr|' \
		${WRKSRC}/gtk/Makefile.in

pre-configure:
.if !exists(${LOCALBASE}/libdata/pkgconfig/cairo-xlib.pc)
	@${ECHO_CMD} "${PKGNAME}: Needs cairo with X11 support enabled."
	@${FALSE}
.endif

pre-build:
	@${RM} -rf ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/loaders
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/modules
	${INSTALL_MAN} ${WRKSRC}/docs/reference/gtk/gtk-query-immodules-2.0.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

.endif

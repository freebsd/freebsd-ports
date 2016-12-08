# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
#    $MCom: ports/x11-toolkits/gtk12/Makefile,v 1.3 2006/10/09 19:31:53 ahze Exp $

PORTNAME=	gtk
PORTVERSION=	1.2.10
PORTREVISION=	25
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/gtk+/1.2
PKGNAMESUFFIX=	12
DISTNAME=	gtk+-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (previous stable version)

USES=		libtool pathfix perl5
USE_PERL5=	build
USE_XORG=	x11 ice xext sm inputproto xi
USE_GNOME=	glib12
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-native-locale \
		--with-xinput=xfree
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

INFO=		gdk gtk

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${MV} ${WRKSRC}/gtk/gtkrc.zh_TW.big5 ${WRKSRC}/gtk/gtkrc.zh_TW.Big5

pre-build:
	${RM} -r ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk/themes/engines
	@${LN} -sf gtk-config ${STAGEDIR}${PREFIX}/bin/gtk12-config

.include <bsd.port.mk>

# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	tsclient
PORTVERSION=	0.150
PORTREVISION=	11
CATEGORIES=	net gnome
MASTER_SITES=	SF

MAINTAINER=	ports@thepentagon.org
COMMENT=	GNOME 2 frontend for rdesktop and vncviewer

RUN_DEPENDS=	rdesktop:net/rdesktop

USE_GNOME=	gtk20 intltool
USES=		gettext gmake gnome libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gnome
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`
LIBS+=		-L${LOCALBASE}/lib `pkg-config --libs libgnomeui-2.0`

PORTDOCS=	COPYING NEWS README

OPTIONS_DEFINE=	TIGHTVNC XNEST DOCS
TIGHTVNC_DESC=	vncviewer support
XNEST_DESC=	X via Xnest support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTIGHTVNC}
RUN_DEPENDS+=	vncviewer:net/tightvnc
.endif

.if ${PORT_OPTIONS:MXNEST}
RUN_DEPENDS+=	Xnest:x11-servers/xorg-nestserver
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^man1dir *=/ s,datadir,prefix,g' \
		${WRKSRC}/Makefile.in

post-install:
	@${LN} -sf tsclient/tsclient.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/tsclient.png
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>

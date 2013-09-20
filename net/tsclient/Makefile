# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	tsclient
PORTVERSION=	0.150
PORTREVISION=	10
CATEGORIES=	net gnome
MASTER_SITES=	SF

MAINTAINER=	ports@thepentagon.org
COMMENT=	GNOME 2 frontend for rdesktop and vncviewer

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk20
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		tsclient.1
PORTDOCS=	COPYING NEWS README

OPTIONS_DEFINE=	GNOME TIGHTVNC XNEST DOCS
OPTIONS_DEFAULT=	GNOME
TIGHTVNC_DESC=	vncviewer support
XNEST_DESC=	X via Xnest support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USES+=		pathfix
USE_GNOME+=	gnomeprefix gnomepanel libgnomeui
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if ${PORT_OPTIONS:MTIGHTVNC}
RUN_DEPENDS+=	vncviewer:${PORTSDIR}/net/tightvnc
.endif

.if ${PORT_OPTIONS:MXNEST}
RUN_DEPENDS+=	Xnest:${PORTSDIR}/x11-servers/xorg-nestserver
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^man1dir *=/ s,datadir,prefix,g' \
		${WRKSRC}/Makefile.in

post-install:
	@${LN} -sf ${PREFIX}/share/pixmaps/tsclient/tsclient.png \
		${PREFIX}/share/pixmaps/tsclient.png
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>

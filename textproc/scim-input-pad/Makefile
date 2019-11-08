# Created by: chinsan	<chinsan@mail2000.com.tw>
# $FreeBSD$

PORTNAME=	scim-input-pad
PORTVERSION=	0.1.3.1
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/${PORTNAME}/0.1.3/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM add-on to input various symbols with customisable on-screen pad

LIB_DEPENDS=	libscim-1.0.so:textproc/scim

USE_LDCONFIG=	yes
USES=		gmake libtool pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

DESKTOP_ENTRIES="SCIM Input Pad" \
		"${COMMENT}" \
		"${PREFIX}/share/scim/icons/input-pad.png" \
		"scim-input-pad" \
		"Utility;" \
		false

DOCS=		ChangeLog README

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext gnome
USE_GNOME=	intlhack
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/^SCIM_LIBEXECDIR=/s|=.*|=${PREFIX}/lib/scim-1.0|' \
		-e '/^SCIM_MODULEDIR=/s|=.*|=${PREFIX}/lib/scim-1.0/1.4.0|' \
		-e '/^SCIM_ICONDIR=/s|=.*|=${PREFIX}/share/scim/icons|' \
		-e '/^SCIM_DATADIR=/s|=.*|=${PREFIX}/share/scim|' \
		-e '/^LIBTOOL_EXPORT_OPTIONS=/s/=.*/=/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|^_NAME|NAME|' ${WRKSRC}/data/*.pad.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

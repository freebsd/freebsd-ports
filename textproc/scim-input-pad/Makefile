# Created by: chinsan	<chinsan@mail2000.com.tw>
# $FreeBSD$

PORTNAME=	scim-input-pad
PORTVERSION=	0.1.3.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/${PORTNAME}/0.1.3/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM add-on to input various symbols with customisable on-screen pad

LIB_DEPENDS=	scim-1.0.10:${PORTSDIR}/textproc/scim

USE_LDCONFIG=	yes
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="SCIM Input Pad" \
		"${COMMENT}" \
		"${PREFIX}/share/scim/icons/input-pad.png" \
		"scim-input-pad" \
		"Utility;" \
		false

DOCS=		ChangeLog README

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
USE_GNOME=	intlhack
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E 's|(SCIM_LIBEXECDIR=).*|\1${PREFIX}/lib/scim-1.0|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E 's|^_NAME|NAME|g' ${WRKSRC}/data/*.pad.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'

.include <bsd.port.mk>

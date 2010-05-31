# New ports collection makefile for:	scim-input-pad
# Date created:		2005/05/06
# Whom:			chinsan	<chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	scim-input-pad
PORTVERSION=	0.1.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM add-on to input various symbols with customisable on-screen pad

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_LDCONFIG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib"

DESKTOP_ENTRIES="SCIM Input Pad" \
		"${COMMENT}" \
		"${PREFIX}/share/scim/icons/input-pad.png" \
		"scim-input-pad" \
		"Utility;" \
		false

DOCS=		ChangeLog README

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
USE_GNOME=	intlhack
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E 's|(SCIM_LIBEXECDIR=).*|\1${PREFIX}/lib/scim-1.0|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'

.include <bsd.port.mk>

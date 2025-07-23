PORTNAME=	tsclient
PORTVERSION=	0.150
PORTREVISION=	14
CATEGORIES=	net gnome
MASTER_SITES=	SF

MAINTAINER=	ports@thepentagon.org
COMMENT=	GNOME 2 frontend for rdesktop and vncviewer
WWW=		https://sourceforge.net/projects/tsclient/

RUN_DEPENDS=	rdesktop:net/rdesktop

USES=		gettext gmake gnome libtool pkgconfig
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-gnome
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	COPYING NEWS README

OPTIONS_DEFINE=	TIGHTVNC XNEST DOCS
TIGHTVNC_DESC=	vncviewer support
XNEST_DESC=	X via Xnest support

TIGHTVNC_RUN_DEPENDS=	vncviewer:net/tightvnc
XNEST_RUN_DEPENDS=	Xnest:x11-servers/xorg-server@xnest

post-install:
	@${LN} -sf tsclient/tsclient.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/tsclient.png
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/bonobo

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>

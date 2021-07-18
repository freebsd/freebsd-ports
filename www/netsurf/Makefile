# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	netsurf
PORTVERSION=	3.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/netsurf/releases/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Lightweight web browser

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	duk:lang/duktape \
		nsgenbind:devel/nsgenbind \
		p5-HTML-Parser>=3.72:www/p5-HTML-Parser \
		xxd:editors/vim-console
LIB_DEPENDS=	libcss.so:textproc/libcss \
		libcurl.so:ftp/curl \
		libdom.so:www/libdom \
		libexpat.so:textproc/expat2 \
		libhubbub.so:www/libhubbub \
		libnsbmp.so:graphics/libnsbmp \
		libnsgif.so:graphics/libnsgif \
		libnspsl.so:dns/libnspsl \
		libnsutils.so:devel/libnsutils \
		libparserutils.so:devel/libparserutils \
		libpng.so:graphics/png \
		libutf8proc.so:textproc/utf8proc \
		libwapcaplet.so:textproc/libwapcaplet \
		libwebp.so:graphics/webp
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		duk:lang/duktape

USES=		bison desktop-file-utils gmake gnome iconv:translit jpeg \
		localbase pkgconfig shebangfix ssl
USE_GNOME=	cairo glib20 gtk30 librsvg2

SHEBANG_FILES=	utils/split-messages.pl
perl_CMD=	${PERL}

MAKE_ARGS=	CC="${CC}" \
		CCOPT="" \
		HOST="${OPSYS}" \
		HOST_CC="${CC}" \
		OPTCFLAGS="${CFLAGS}" \
		Q="" \
		TARGET="gtk3" \
		WARNFLAGS=""
MAKE_ENV+=	COMPONENT_TYPE="lib-shared" \
		FLEX="${LOCALBASE}/bin/flex"

ALL_TARGET=	#empty
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lssl -lcrypto
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

post-patch:
	@${REINPLACE_CMD} '/CFLAGS/d' \
		${WRKSRC}//Makefile.defaults
	@${CP} ${FILESDIR}/buildui.pl ${WRKSRC}/utils/

do-configure:
	@${CP} ${FILESDIR}/Makefile.config  ${WRKSRC}

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf netsurf-gtk3 \
		netsurf-gtk
.for d in applications pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/frontends/gtk/res/deoptions.gtk3.ui \
		${STAGEDIR}${PREFIX}/share/netsurf
	${INSTALL_DATA} ${WRKSRC}/frontends/gtk/res/enoptions.gtk3.ui \
		${STAGEDIR}${PREFIX}/share/netsurf
	${INSTALL_DATA} ${WRKSRC}/frontends/gtk/res/froptions.gtk3.ui \
		${STAGEDIR}${PREFIX}/share/netsurf
	${INSTALL_DATA} ${WRKSRC}/frontends/gtk/res/itoptions.gtk3.ui \
		${STAGEDIR}${PREFIX}/share/netsurf
	${INSTALL_DATA} ${WRKSRC}/frontends/gtk/res/nloptions.gtk3.ui \
		${STAGEDIR}${PREFIX}/share/netsurf
	${INSTALL_DATA} ${WRKSRC}/frontends/gtk/res/netsurf-gtk.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/frontends/gtk/res/netsurf.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>

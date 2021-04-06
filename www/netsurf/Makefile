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
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libnsutils.so:devel/libnsutils \
		libutf8proc.so:textproc/utf8proc \
		libnsgif.so:graphics/libnsgif \
		libnsbmp.so:graphics/libnsbmp \
		libdom.so:www/libdom \
		libcss.so:textproc/libcss \
		libparserutils.so:devel/libparserutils \
		libwapcaplet.so:textproc/libwapcaplet \
		libhubbub.so:www/libhubbub \
		libexpat.so:textproc/expat2 \
		libnspsl.so:dns/libnspsl \
		libwebp.so:graphics/webp
RUN_DEPENDS=	duk:lang/duktape \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		bison desktop-file-utils gmake gnome jpeg \
		localbase pkgconfig shebangfix ssl iconv:translit
ALL_TARGET=	#empty
LDFLAGS+=	-L${OPENSSLLIB} -lssl -lcrypto
CFLAGS+=	-I${OPENSSLINC}
MAKE_ARGS=	HOST_CC="${CC}" CC="${CC}" CCOPT="" HOST="${OPSYS}" \
		TARGET="gtk3" \
		WARNFLAGS="" Q="" OPTCFLAGS="${CFLAGS}"
MAKE_ENV+=	COMPONENT_TYPE="lib-shared" \
		FLEX="${LOCALBASE}/bin/flex"
USE_GNOME=	glib20 gtk30 cairo librsvg2
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

SHEBANG_FILES=	utils/split-messages.pl
perl_CMD=	${PERL}

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

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

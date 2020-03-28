# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netsurf
PORTVERSION=	3.9
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/netsurf/releases/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
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
		libnspsl.so:dns/libnspsl
RUN_DEPENDS=	duk:lang/duktape \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		bison desktop-file-utils gettext-runtime gmake gnome iconv jpeg \
		localbase pkgconfig shebangfix ssl
ALL_TARGET=	#empty
LDFLAGS+=	-L${OPENSSLLIB} -lssl -lcrypto ${ICONV_LIB}
CFLAGS+=	-I${OPENSSLINC}
MAKE_ARGS=	HOST_CC="${CC}" CC="${CC}" CCOPT="" HOST="${OPSYS}" \
		TARGET="gtk3" \
		WARNFLAGS="" Q="" OPTCFLAGS="${CFLAGS}"
MAKE_ENV+=	COMPONENT_TYPE="lib-shared" \
		FLEX="${LOCALBASE}/bin/flex"
USE_GNOME=	glib20 gtk30 cairo librsvg2
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

SHEBANG_FILES=	utils/split-messages.pl
perl_CMD=	${SETENV} perl

OPTIONS_DEFINE=		GSTREAMER
OPTIONS_EXCLUDE=	GSTREAMER
GSTREAMER_USE=		GSTREAMER=yes, good

post-patch:
	@${REINPLACE_CMD} '/CFLAGS/d' \
		${WRKSRC}//Makefile.defaults
	@${REINPLACE_CMD} 's| -O2||' \
		${WRKSRC}/frontends/gtk/Makefile.defaults
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/frontends/gtk/gui.c

do-configure:
	@${CP} ${FILESDIR}/Makefile.config  ${WRKSRC}
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} '/NETSURF_USE_LIBICONV_PLUG/ s|NO|YES|' \
		${WRKSRC}/Makefile.config
.endif

do-configure-GSTREAMER-on:
	@${REINPLACE_CMD} '/NETSURF_USE_VIDEO/ s|NO|YES|' \
		${WRKSRC}/Makefile.config

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf netsurf-gtk3 \
		netsurf-gtk
.for d in applications pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/frontends/gtk/res/netsurf-gtk.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/frontends/gtk/res/netsurf.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>

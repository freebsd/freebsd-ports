# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netsurf
PORTVERSION=	3.5
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/netsurf/releases/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Lightweight web browser

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	duk:lang/duktape \
		nsgenbind:devel/nsgenbind \
		p5-HTML-Parser>=3.72:www/p5-HTML-Parser
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libnsutils.so:devel/libnsutils \
		libutf8proc.so:textproc/libutf8proc \
		libnsgif.so:graphics/libnsgif \
		libnsbmp.so:graphics/libnsbmp \
		libdom.so:www/libdom \
		libcss.so:textproc/libcss

ALL_TARGET=	#empty
LDFLAGS+=	-lssl -lcrypto -L${LOCALBASE}/lib ${ICONV_LIB}
MAKE_ARGS=	HOST_CC="${CC}" CC="${CC}" CCOPT="" HOST="${OPSYS}" \
		WARNFLAGS="" Q="" OPTCFLAGS="${CFLAGS}"
MAKE_ENV+=	COMPONENT_TYPE="lib-shared" \
		FLEX="${LOCALBASE}/bin/flex"
USES=		bison desktop-file-utils gmake iconv jpeg \
		localbase perl5 pkgconfig shebangfix
USE_GNOME=	glib20 gtk20 librsvg2

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

SHEBANG_FILES=	utils/split-messages.pl
perl_CMD=	${SETENV} perl

OPTIONS_DEFINE=	GSTREAMER
GSTREAMER_USE=		GSTREAMER=yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} '/CFLAGS/d' \
		${WRKSRC}//Makefile.defaults
	@${REINPLACE_CMD} 's| -O2||' \
		${WRKSRC}/gtk/Makefile.defaults
	@${REINPLACE_CMD} \
		-e '/OpenSSL/d' -e 's| -g||' \
		-e 's/-DG_DISABLE_DEPRECATED//' \
		${WRKSRC}/gtk/Makefile.target
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/gtk/gui.c

do-configure:
	@${CP} ${FILESDIR}/Makefile.config  ${WRKSRC}
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} '/NETSURF_USE_LIBICONV_PLUG/ s|NO|YES|' \
		${WRKSRC}/Makefile.config
.endif
.if ${PORT_OPTIONS:MGSTREAMER}
	@${REINPLACE_CMD} '/NETSURF_USE_VIDEO/ s|NO|YES|' \
		${WRKSRC}/Makefile.config
.endif

.include <bsd.port.post.mk>

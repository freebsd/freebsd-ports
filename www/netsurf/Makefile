# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netsurf
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/netsurf/releases/source-full/
DISTNAME=	${PORTNAME}-${PORTVERSION}-full-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight web browser

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

ALL_TARGET=	#empty
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lssl -lcrypto -L${LOCALBASE}/lib ${ICONV_LIB}
MAKE_ARGS=	HOST_CC="${CC}" CC="${CC}" CCOPT="" HOST="${OPSYS}" \
		WARNFLAGS="" Q="" OPTCFLAGS="${CFLAGS}"
USES=		bison gmake pkgconfig iconv
USE_GNOME=	gtk20 librsvg2

NSFB_VERSION=	0.1.0
WRKSRC=		${WRKDIR}/${PORTNAME}-full-${PORTVERSION}

DESKTOP_ENTRIES="NetSurf" "${COMMENT}" "${DATADIR}/${PORTNAME}.xpm" \
		"${PORTNAME}" "" "true"

OPTIONS_DEFINE=	GSTREAMER WEBP
GSTREAMER_USE=		GSTREAMER=yes
WEBP_LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp

.include <bsd.port.options.mk>

.if ${OPSYS} == DragonFly
LIB_DEPENDS+=	libssl.so:${PORTSDIR}/security/openssl
BUILD_DEPENDS+=	gperf:${PORTSDIR}/devel/gperf
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} '/^NSFB_LINUX_AVAILABLE/ s|yes|no| ; s| -g||' \
		${WRKSRC}/src/libnsfb-${NSFB_VERSION}/Makefile
	@${REINPLACE_CMD} 's|endian|sys/endian|' \
		${WRKSRC}/src/libnsfb-${NSFB_VERSION}/src/plot/*bpp*.c
	@${REINPLACE_CMD} '/CFLAGS/d' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/Makefile.defaults
	@${REINPLACE_CMD} 's| -O2||' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/gtk/Makefile.defaults
	@${REINPLACE_CMD} \
		-e '/OpenSSL/d' -e '/lcms/d' -e 's| -g||' \
		-e 's/-DG_DISABLE_DEPRECATED//' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/gtk/Makefile.target
	@${REINPLACE_CMD} -e 's| -g|| ; s|flex|${LOCALBASE}/bin/&|' \
		${WRKSRC}/src/nsgenbind-0.0.1/src/Makefile

do-configure:
	@${CP} ${FILESDIR}/Makefile.config  ${WRKSRC}/src/netsurf-${PORTVERSION}
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} '/NETSURF_USE_LIBICONV_PLUG/ s|NO|YES|' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/Makefile.config	
.endif
.if ${PORT_OPTIONS:MGSTREAMER}
	@${REINPLACE_CMD} '/NETSURF_USE_VIDEO/ s|NO|YES|' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/Makefile.config
.endif
.if ${PORT_OPTIONS:MWEBP}
	@${REINPLACE_CMD} '/NETSURF_USE_WEBP/ s|NO|YES|' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/Makefile.config
.endif

.include <bsd.port.post.mk>

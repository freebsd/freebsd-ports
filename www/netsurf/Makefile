# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netsurf
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/netsurf/releases/source-full/
DISTNAME=	${PORTNAME}-${PORTVERSION}-full-src

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Lightweight web browser

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		mng:${PORTSDIR}/graphics/libmng

ALL_TARGET=	#empty
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	HOST_CC="${CC}" CC="${CC}" CCOPT="" HOST="${OPSYS}" \
		WARNFLAGS="" Q="" OPTCFLAGS="${CFLAGS}"
USES=		bison gmake
USE_GNOME=	librsvg2
MAKE_JOBS_UNSAFE=	yes

NSFB_VERSION=	0.1.0
WRKSRC=		${WRKDIR}/${PORTNAME}-full-${PORTVERSION}

DESKTOP_ENTRIES="NetSurf" "${COMMENT}" "" "${PORTNAME}" "" "true"

OPTIONS_DEFINE=	GSTREAMER WEBP

WEBP_LIB_DEPENDS=	webp:${PORTSDIR}/graphics/webp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
.endif

post-patch:
	@${REINPLACE_CMD} '/^NSFB_LINUX_AVAILABLE/ s|yes|no| ; s| -g||' \
		${WRKSRC}/src/libnsfb-${NSFB_VERSION}/Makefile
	@${REINPLACE_CMD} 's|endian|sys/endian|' \
		${WRKSRC}/src/libnsfb-${NSFB_VERSION}/src/plot/*bpp*.c
	@${REINPLACE_CMD} 's| -O2||' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/gtk/Makefile.defaults
	@${REINPLACE_CMD} '/OpenSSL/d ; s| -g||' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/gtk/Makefile.target
	@${REINPLACE_CMD} -e '/ifeq.*clang/s/word 1/filter clang/' \
		${WRKSRC}/src/buildsystem-1.0/makefiles/Makefile.tools
	@${REINPLACE_CMD} -e 's| -g|| ; s|flex|${LOCALBASE}/bin/&|' \
		${WRKSRC}/src/nsgenbind-0.0.1/src/Makefile

do-configure:
	@${CP} ${FILESDIR}/Makefile.config  ${WRKSRC}/src/netsurf-${PORTVERSION}
.if ${PORT_OPTIONS:MGSTREAMER}
	@${REINPLACE_CMD} '/NETSURF_USE_VIDEO/ s|NO|YES|' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/Makefile.config
.endif
.if ${PORT_OPTIONS:MWEBP}
	@${REINPLACE_CMD} '/NETSURF_USE_WEBP/ s|NO|YES|' \
		${WRKSRC}/src/netsurf-${PORTVERSION}/Makefile.config
.endif

.include <bsd.port.mk>

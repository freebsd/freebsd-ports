# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tvheadend
PORTVERSION=	3.4.0.20130726.3
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freebsd.org/~decke/distfiles/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} dvb-scan-tables-20130714.tar.gz

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A TV streaming server supporting DVB, IPTV and V4L

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		curl:${PORTSDIR}/ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	decke
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	8a8c1a8

USES=		pkgconfig gmake
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	AVAHI

CONFIGURE_ENV+=	PLATFORM=freebsd \
		CFLAGS+="-I${LOCALBASE}/include" \
		LDFLAGS+="-L${LOCALBASE}/lib -lexecinfo -lssl -lz"
CONFIGURE_ARGS+=	--disable-dvbscan --disable-zlib
CFLAGS+=	-Wno-conversion -Wno-int-to-pointer-cast

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64" || ${ARCH} == "mips64"
CFLAGS+=	-D__WORDSIZE=64
.else
CFLAGS+=	-D__WORDSIZE=32
.endif
.endif

.if ( !empty(CC:M*clang*) || ${OSVERSION} >= 1000024 )
# CLANG also needs -Wno-microsoft which GCC 4.2 does not know
CFLAGS+=	-Wno-microsoft \
		-Wno-tautological-constant-out-of-range-compare
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.endif

post-patch:
	@${REINPLACE_CMD} 's|-g||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|-ldl||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/Autobuild.sh \
		${WRKSRC}/configure \
		${WRKSRC}/support/changelog \
		${WRKSRC}/support/configure.inc \
		${WRKSRC}/support/getmuxlist \
		${WRKSRC}/support/pbuilder \
		${WRKSRC}/support/version
	@${REINPLACE_CMD} 's|/usr/share/dvb|${DATADIR}/dvb|' \
		${WRKSRC}/src/muxes.c

post-install:
	${MKDIR} ${DATADIR}/dvb
	${CP} -a ${WRKDIR}/dvb-scan-tables/ ${DATADIR}/dvb
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

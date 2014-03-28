# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr
PORTVERSION=	1.7.29
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.tvdr.de/vdr/Developer/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - development version

BUILD_DEPENDS=  v4l_compat>=1.0.20120501:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=    libjpeg.so:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=		IPTVPATCH TTXPATCH STB0899_SIGNAL
IPTVPATCH_DESC=		Stops EIT scans on IPTV channels
TTXPATCH_DESC=		Support patches for teletext subtitle plugin
DVBPATCH_DESC=		DVB audio patch for some countries
STB0899_SIGNAL_DESC=	STB0899 signal strength patch
OPTIONS_DEFAULT=	IPTVPATCH TTXPATCH

USES=		pkgconfig gettext iconv:wchar_t gmake tar:bzip2
DIST_SUBDIR=	vdr
PORTDOCS=	COPYING INSTALL MANUAL README HISTORY
CONFDIR=	$(ETCDIR)
USE_CSTD=	gnu89
MAKE_ARGS+=	CC=${CC}
MAKE_ARGS+=	CXX=${CXX}
MAKE_ARGS+=	VDR_USER=${VDR_USER}
MAKE_ARGS+=	CONFDIR=$(CONFDIR)
MAKE_ARGS+=	OSTYPE=FreeBSD
MAKE_ARGS+=	LIRC_DEVICE=/var/run/lirc/lircd
MAKE_ARGS+=	LIBDIR=../../lib
MAKE_ARGS+=	VDRDIR=${WRKSRC}
MAKE_ARGS+=	TMPDIR=/tmp
MAKE_ARGS+=	PREFIX=${PREFIX}
ALL_TARGET=	all plugins

VIDEODIR=	/video
SUB_LIST+=	VIDEODIR=${VIDEODIR}
SUB_FILES+=	vdr-waitdvb
USE_RC_SUBR=	vdr
VDR_USER=	vdr
VDR_GROUP=	vdr
USERS=		${VDR_USER}
GROUPS=		${VDR_GROUP}
PLIST_SUB=	VDR_USER=${VDR_USER}
PLIST_SUB+=	VDR_GROUP=${VDR_GROUP}

.include <bsd.port.options.mk>

EXTRA_PATCHES+=	${FILESDIR}/vdr-1.7.15-disable_ca_updates.patch
.if ${PORT_OPTIONS:MIPTVPATCH}
EXTRA_PATCHES+=	${FILESDIR}/vdr-1.7.15-disable_eitscan.patch
.endif
.if ${PORT_OPTIONS:MDVBPATCH}
EXTRA_PATCHES+=	${FILESDIR}/vdr-1.7.27-pat.diff
.endif

.if ${PORT_OPTIONS:MTTXPATCH}
PLIST_SUB+=	TTXPATCH=""
.else
PLIST_SUB+=	TTXPATCH="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
ALL_TARGET=	vdr plugins
.endif

post-patch:
# clang doesn't know -MG:
	@${REINPLACE_CMD} -e '/^MAKEDEP.*-MM/s/-MG[[:space:]]*$$/# -MG/' \
		${WRKSRC}/Makefile ${WRKSRC}/libsi/Makefile \
		${WRKSRC}/PLUGINS/src/*/Makefile
	@[ ! -f ${WRKSRC}/s2apiwrapper.c ] || \
		${REINPLACE_CMD} 's/__u32/uint32_t/' ${WRKSRC}/s2apiwrapper.c
.if ${PORT_OPTIONS:MTTXPATCH}
	@${PATCH} -d ${WRKSRC} --quiet -p1 <${FILESDIR}/vdr-1.7.21-ttxtsubs.patch-1
	@${PATCH} -d ${WRKSRC} --quiet -p1 <${FILESDIR}/vdr-1.7.21-ttxtsubs.patch-2
.endif
.if ${PORT_OPTIONS:MSTB0899_SIGNAL}
# This fixes signal strength display for e.g. pctv452e-based tuners.
# (like TT S2-36?0.)
	@${PATCH} -d ${WRKSRC} --quiet -p1 <${FILESDIR}/stb0899-signalstrength.patch
.endif
	@${SED} \
		-e '/^PREFIX/d' \
		-e 's|^\(VIDEODIR[[:space:]]*\)[?]*\(=[[:space:]]*\).*|\1\2${VIDEODIR}|' \
		${WRKSRC}/Make.config.template >${WRKSRC}/Make.config
	@${REINPLACE_CMD} -e 's|%%CONFDIR%%|${CONFDIR}|' ${WRKSRC}/vdr.1
# We don't support this yet:
	@${RM} -r ${WRKSRC}/PLUGINS/src/dvbhddevice

post-install:
.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} locale ${STAGEDIR}${PREFIX}/share/)
.endif
	${MKDIR} ${STAGEDIR}${CONFDIR}/plugins
	${INSTALL_DATA} ${FILESDIR}/remote.conf ${STAGEDIR}${CONFDIR}/remote.conf.sample
	for i in $$(cd ${WRKSRC} && ls *.conf); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${STAGEDIR}${CONFDIR}/$$i.sample; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/vdr-waitdvb ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>

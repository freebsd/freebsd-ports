# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr
PORTVERSION=	1.7.29
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.tvdr.de/vdr/Developer/
DIST_SUBDIR=	vdr

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - development version

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=  v4l_compat>=1.0.20120501:multimedia/v4l_compat \
		${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:x11-fonts/fontconfig \
		xorg-fonts-truetype>=0:x11-fonts/xorg-fonts-truetype

USES=		cpe gettext gmake iconv:wchar_t jpeg pkgconfig shebangfix tar:bzip2
CPE_VENDOR=	tvdr
SHEBANG_FILES=	svdrpsend
CONFDIR=	${ETCDIR}
USE_CSTD=	gnu89
MAKE_ARGS=	CC="${CC}" \
		CXX="${CXX}" \
		VDR_USER=${VDR_USER} \
		CONFDIR=${CONFDIR} \
		OSTYPE=FreeBSD \
		LIRC_DEVICE=/var/run/lirc/lircd \
		LIBDIR=../../lib \
		VDRDIR=${WRKSRC} \
		TMPDIR=/tmp \
		PREFIX=${PREFIX}
ALL_TARGET=	all plugins

VDR_USER=	vdr
VDR_GROUP=	vdr

VIDEODIR=	/video
SUB_LIST=	VIDEODIR=${VIDEODIR}
SUB_FILES=	vdr-waitdvb
USE_RC_SUBR=	vdr
USERS=		${VDR_USER}
GROUPS=		${VDR_GROUP}
PLIST_SUB=	VDR_USER=${VDR_USER} \
		VDR_GROUP=${VDR_GROUP}

PORTDOCS=	INSTALL MANUAL README HISTORY

OPTIONS_DEFINE=		IPTVPATCH TTXPATCH STB0899_SIGNAL DOCS NLS
OPTIONS_DEFAULT=	IPTVPATCH TTXPATCH
OPTIONS_SUB=		yes

IPTVPATCH_DESC=		Stops EIT scans on IPTV channels
TTXPATCH_DESC=		Support patches for teletext subtitle plugin
STB0899_SIGNAL_DESC=	STB0899 signal strength patch

IPTVPATCH_EXTRA_PATCHES=	${FILESDIR}/vdr-1.7.15-disable_eitscan.patch

NLS_ALL_TARGET=	vdr plugins

.include <bsd.port.options.mk>

.if ${OPSYS} == DragonFly
IGNORE=		will not work due to lack of driver support
.endif

.if ${ARCH} == "i386"
USE_GCC=	any
.endif

post-patch:
# clang doesn't know -MG:
	@${REINPLACE_CMD} -e '/^MAKEDEP.*-MM/s/-MG[[:space:]]*$$/# -MG/' \
		${WRKSRC}/Makefile ${WRKSRC}/libsi/Makefile \
		${WRKSRC}/PLUGINS/src/*/Makefile
	@[ ! -f ${WRKSRC}/s2apiwrapper.c ] || \
		${REINPLACE_CMD} 's/__u32/uint32_t/' ${WRKSRC}/s2apiwrapper.c
	@${SED} \
		-e '/^PREFIX/d' \
		-e 's|^\(VIDEODIR[[:space:]]*\)[?]*\(=[[:space:]]*\).*|\1\2${VIDEODIR}|' \
		${WRKSRC}/Make.config.template >${WRKSRC}/Make.config
	@${REINPLACE_CMD} -e 's|%%CONFDIR%%|${CONFDIR}|' ${WRKSRC}/vdr.1
# We don't support this yet:
	@${RM} -r ${WRKSRC}/PLUGINS/src/dvbhddevice

post-patch-TTXPATCH-on:
	@${PATCH} -d ${WRKSRC} --quiet -p1 <${FILESDIR}/vdr-1.7.21-ttxtsubs.patch-1
	@${PATCH} -d ${WRKSRC} --quiet -p1 <${FILESDIR}/vdr-1.7.21-ttxtsubs.patch-2

post-patch-STB0899_SIGNAL-on:
# This fixes signal strength display for e.g. pctv452e-based tuners.
# (like TT S2-36?0.)
	@${PATCH} -d ${WRKSRC} --quiet -p1 <${FILESDIR}/stb0899-signalstrength.patch

post-install:
	@${MKDIR} ${STAGEDIR}${CONFDIR}/plugins
	${INSTALL_DATA} ${FILESDIR}/remote.conf ${STAGEDIR}${CONFDIR}/remote.conf.sample
	for i in $$(cd ${WRKSRC} && ls *.conf); do \
		${MV} -i ${STAGEDIR}${CONFDIR}/$$i \
			${STAGEDIR}${CONFDIR}/$$i.sample; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/vdr-waitdvb ${STAGEDIR}${PREFIX}/bin

post-install-NLS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} locale ${STAGEDIR}${PREFIX}/share/)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

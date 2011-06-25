# New ports collection makefile for:	vdr
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr
PORTVERSION=	1.7.19
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.tvdr.de/vdr/Developer/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - development version

BUILD_DEPENDS=  ${LOCALBASE}/include/linux/dvb/frontend.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=    jpeg.11:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS=	IPTVPATCH "Stops EIT scans on IPTV channels" On \
		TTXPATCH "Support patches for teletext subtitle plugin" On

DIST_SUBDIR=	vdr
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME+=	pkgconfig
USE_GETTEXT=	yes
PORTDOCS=	COPYING INSTALL MANUAL README
MAKE_JOBS_SAFE=	yes
MAN1=		vdr.1
MAN5=		vdr.5
MANCOMPRESSED=	yes
CONFDIR=	$(ETCDIR)
USE_CSTD=	gnu89
MAKE_ARGS+=	CC=${CC}
MAKE_ARGS+=	CXX=${CXX}
MAKE_ARGS+=	DVBDIR=${LOCALBASE}/include
MAKE_ARGS+=	VDR_USER=${VDR_USER}
MAKE_ARGS+=	CONFDIR=$(CONFDIR)
MAKE_ARGS+=	OSTYPE=FreeBSD
MAKE_ARGS+=	LIRC_DEVICE=/var/run/lirc/lircd
ALL_TARGET=	all plugins

VIDEODIR=	/video
SUB_LIST+=	VIDEODIR=${VIDEODIR}
USE_RC_SUBR=	vdr
VDR_USER=	vdr
VDR_GROUP=	vdr
USERS=		${VDR_USER}
GROUPS=		${VDR_GROUP}
PLIST_SUB=	VDR_USER=${VDR_USER}
PLIST_SUB+=	VDR_GROUP=${VDR_GROUP}

.include <bsd.port.options.mk>

EXTRA_PATCHES+=	${FILESDIR}/vdr-1.7.15-disable_ca_updates.patch
.if defined(WITH_IPTVPATCH)
EXTRA_PATCHES+=	${FILESDIR}/vdr-1.7.15-disable_eitscan.patch
.endif

.if defined(WITH_TTXPATCH)
PLIST_SUB+=	TTXPATCH=""
.else
PLIST_SUB+=	TTXPATCH="@comment "
.endif

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
ALL_TARGET=	vdr plugins
.endif

post-patch:
# avoid a bug found post-release by reverting parts of the 1.7.19 update
# thread:
#	http://thread.gmane.org/gmane.linux.vdr/44724/focus=44729
	@${PATCH} -d ${WRKSRC} --quiet -p1 -R <${FILESDIR}/vdr-1.7.18-1.7.19-tspacketbug.diff
# clang doesn't know -MG:
	@${REINPLACE_CMD} '/^MAKEDEP.*-MM/s/-MG[[:space:]]*$$/# -MG/' \
		${WRKSRC}/Makefile ${WRKSRC}/libsi/Makefile \
		${WRKSRC}/PLUGINS/src/*/Makefile
.if defined(WITH_TTXPATCH)
	@${PATCH} -d ${WRKSRC} --quiet -p1 <${FILESDIR}/vdr-1.7.15-ttxtsubs.patch-1
	@${PATCH} -d ${WRKSRC} --quiet -p1 <${FILESDIR}/vdr-1.7.15-ttxtsubs.patch-2
	@${PATCH} -d ${WRKSRC} --quiet -p1 <${FILESDIR}/vdr-1.7.19-ttxtsubs.patch-3
.endif
	@${SED} 's|^\(VIDEODIR[[:space:]]*\)[?]*\(=[[:space:]]*\).*|\1\2${VIDEODIR}|' \
		${WRKSRC}/Make.config.template >${WRKSRC}/Make.config
	@${REINPLACE_CMD} -e 's|%%CONFDIR%%|${CONFDIR}|' ${WRKSRC}/vdr.1
# We don't support this yet:
	@${RM} -r ${WRKSRC}/PLUGINS/src/dvbhddevice

post-install:
.if !defined(WITHOUT_NLS)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} locale ${PREFIX}/share/)
.endif
	${MKDIR} ${CONFDIR}/plugins
	${CHOWN} ${VDR_USER}:${VDR_GROUP} ${CONFDIR} ${CONFDIR}/plugins
	${INSTALL_DATA} ${FILESDIR}/remote.conf ${CONFDIR}/remote.conf.sample
	@if [ ! -f ${CONFDIR}/remote.conf ]; then \
	    ${INSTALL_DATA} -o ${VDR_USER} -g ${VDR_GROUP} ${FILESDIR}/remote.conf ${CONFDIR}; \
	fi
	for i in $$(cd ${WRKSRC} && ls *.conf); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${CONFDIR}/$$i.sample; \
		if [ ! -f ${CONFDIR}/$$i ]; then \
			${INSTALL_DATA} -o ${VDR_USER} -g ${VDR_GROUP} ${WRKSRC}/$$i ${CONFDIR}/$$i; \
		fi; \
	done
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>

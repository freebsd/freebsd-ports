# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/www/flock/Makefile,v 1.4 2009/01/09 23:41:22 mezz Exp $
#

PORTNAME=	flock
DISTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/${PORTNAME}/releases/${PORTVERSION}/ \
		http://flock.vo.llnwd.net/o23/archive/${PORTNAME}/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nss>=3.11.2:${PORTSDIR}/security/nss
LIB_DEPENDS=	clucene.0:${PORTSDIR}/textproc/clucene \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg

MOZILLA_NAME=	Flock

WRKSRC?=	${WRKDIR}/${PORTNAME}/mozilla
WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
EXTRA_CFLAGS=	-O2
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_PERL=	yes
GECKO_PLIST_PRE_FILES=	lib/${MOZILLA}/chrome/icons/default/default.xpm
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA}/chrome/icons/default lib/${MOZILLA}/chrome/icons

FLOCK_ICON=	${MOZILLA}.xpm
FLOCK_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/icons/default.xpm
MOZ_OPTIONS=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--enable-application=browser \
		--enable-system-cairo	\
		--enable-official-branding \
		--enable-canvas	\
		--with-system-nss \
		--with-clucene-prefix=${LOCALBASE} \
		--with-ffmpeg-prefix=${LOCALBASE}

SYSTEM_PREFS=		${FAKEDIR}/lib/${MOZILLA}/defaults/pref/${PORTNAME}.js
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

OPTIONS=	SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 pthread | ${SED} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

.if ${ARCH} != "i386"
BROKEN=	does not compile
.endif

.if ${ARCH} == "sparc64" && ${OSVERSION} < 601101
IGNORE=	does not run, update to 6.2-RELEASE or newer
.endif

MOZ_OPTIONS+=	--enable-svg --enable-svg-renderer=cairo

post-extract::
	@${SED} -e 's|@FLOCK_ICON@|${FLOCK_ICON}|' -e 's|@MOZILLA@|${MOZILLA}|' \
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|' \
		<${FILESDIR}/flock.desktop.in >${WRKDIR}/${MOZILLA}.desktop

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${WRKSRC}/storage/build/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in
	@${FIND} ${WRKSRC} -name all.js | ${XARGS} ${REINPLACE_CMD} -e \
		'/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/'

pre-install:
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${FLOCK_ICON}' >> ${PLIST}

post-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${MKDIR} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default
	${LN} -sf ${FLOCK_ICON_SRC} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default.xpm
	${LN} -sf ${FLOCK_ICON_SRC} ${PREFIX}/share/pixmaps/${FLOCK_ICON}

.include "${PORTSDIR}/www/mozilla/Makefile.common"
.include <bsd.port.post.mk>

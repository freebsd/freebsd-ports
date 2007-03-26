# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/flock/Makefile,v 1.2 2006/10/05 21:37:18 mezz Exp $
#

PORTNAME=	flock
DISTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
# http://ftp.osuosl.org/pub/${PORTNAME}/source/${PORTVERSION}/:flock
MASTER_SITE_SUBDIR=	ahze
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		clucene-flock-3${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

LIB_DEPENDS=	GraphicsMagick.1:${PORTSDIR}/graphics/GraphicsMagick \
		jasper.4:${PORTSDIR}/graphics/jasper

MOZILLA_NAME=	Flock
CLUCENE_WRKSRC=	${WRKDIR}/clucene
WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	3.4+

CPPFLAGS=	-I${WRKDIR}/local/include
LDFLAGS=	-L${WRKDIR}/local/lib

GECKO_PLIST_PRE_FILES=	lib/${MOZILLA}/chrome/icons/default/default.xpm
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA}/chrome/icons/default lib/${MOZILLA}/chrome/icons

FLOCK_ICON=		${MOZILLA}.xpm
FLOCK_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/icons/default.xpm
CONFIGURE_ARGS=	--with-clucene-prefix=${WRKDIR}/local
MOZ_OPTIONS=	--enable-application=browser \
		--enable-system-cairo	\
		--enable-official-branding \
		--enable-canvas

MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

OPTIONS=	SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not build on amd64
.endif

.if ${ARCH}=="alpha" || ${ARCH}=="ia64"
IGNORE=	core dumps on ${ARCH}
.endif

.if ${ARCH}=="sparc64" && ${OSVERSION} < 601101
IGNORE=	core dumps on ${ARCH}, need kern.osreldate>=601101
.endif

.if ${OSVERSION} >= 600000
MOZ_OPTIONS+=	--enable-svg --enable-svg-renderer=cairo
.endif

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

post-extract::
	@${SED} -e 's|@FLOCK_ICON@|${FLOCK_ICON}|' -e 's|@MOZILLA@|${MOZILLA}|' \
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|' \
		<${FILESDIR}/flock.desktop.in >${WRKDIR}/${MOZILLA}.desktop

pre-build:
	@(cd ${CLUCENE_WRKSRC} && ${SETENV} LIBS="-lcompat" \
		CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \./configure --prefix=${WRKDIR}/local --disable-shared)
	@(cd ${CLUCENE_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} all)
	@(cd ${CLUCENE_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install)

pre-install:
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${FLOCK_ICON}' >> ${PLIST}
	${ECHO_CMD} "@dirrmtry share/pixmaps" >> ${PLIST}

do-install:
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
				${LN} -sf $${jpi} \
					${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ; \
				break; \
			fi; \
		done; \
	fi

post-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${MKDIR} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default
	${LN} -sf ${FLOCK_ICON_SRC} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default.xpm
	${LN} -sf ${FLOCK_ICON_SRC} ${PREFIX}/share/pixmaps/${FLOCK_ICON}

.include "${PORTSDIR}/www/mozilla/Makefile.common"
.include <bsd.port.post.mk>

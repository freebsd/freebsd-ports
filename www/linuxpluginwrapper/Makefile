# New ports collection makefile for:	linuxpluginwrapper
# Date Created:				2003-06-15
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linuxpluginwrapper
PORTVERSION=	20051113
PORTREVISION=	10
CATEGORIES=	www linux emulators
MASTER_SITES=	http://people.FreeBSD.org/~nork/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork

PATCH_SITES=	http://defan.zenon.net/freebsd/
PATCHFILES=	patch-nppdf-acroread-7.0.8

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper allowing use of linux-plugins with native applications

OPTIONS=	REALPLAYER	"install linux-realplayer"	off

.include <bsd.port.pre.mk>

.if		 ${OSVERSION} >= 700009
IGNORE=		doesn't support ELF symbol versioning, yet.
.endif

# I will remove WITH_PLUGINS knob.
.if		defined(WITH_REALPLAYER)
RUN_DEPENDS+=	${LOCALBASE}/lib/linux-mozilla/plugins/nphelix.so:${PORTSDIR}/multimedia/linux-realplayer
WITH_PLUGINS=	1
.endif

ONLY_FOR_ARCHS=	i386
MAKE_ENV=	EXAMPLESDIR=${EXAMPLESDIR} INSTALL_DATA="${INSTALL_DATA}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"

CONFLICTS=	flashpluginwrapper-*
USE_XLIB=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}
PKGMESSAGE=	${WRKDIR}/pkg-message
.if		!defined(WITH_PLUGINS)
PLIST=		${WRKDIR}/pkg-plist
.endif

LIBMAPCONF=	${EXAMPLESDIR}/libmap.conf-FreeBSD6

.if		defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG=1
.endif

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		-e 's,%%X11BASE%%,${LOCALBASE},' \
		-e 's,%%LTHREADSHMAJOR%%,${LTHREADSHMAJOR},' \
		-e 's,%%LIBMAPCONF%%,${LIBMAPCONF},' \
		< ${.CURDIR}/pkg-message > ${PKGMESSAGE}
.if		!defined(WITH_PLUGINS)
	@${SED} -e "/exec/d" ${.CURDIR}/pkg-plist > ${PLIST}
.endif

.if		defined(WITH_PLUGINS)
pre-install:
	@${MKDIR} ${LOCALBASE}/lib/browser_linux_plugins
.if		defined(WITH_REALPLAYER)
	@${LN} -sf ${LOCALBASE}/lib/linux-mozilla/plugins/nphelix.so \
		${LOCALBASE}/lib/browser_linux_plugins/
	@${LN} -sf ${LOCALBASE}/lib/linux-mozilla/plugins/nphelix.xpt \
		${LOCALBASE}/lib/browser_linux_plugins/
.endif
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

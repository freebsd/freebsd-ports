# New ports collection makefile for:	linuxpluginwrapper
# Date Created:				2003-06-15
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linuxpluginwrapper
PORTVERSION=	20051113
PORTREVISION=	3
CATEGORIES=	www linux emulators
MASTER_SITES=	http://people.FreeBSD.org/~nork/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork

MAINTAINER=	nork@FreeBSD.org
COMMENT=	A wrapper allowing use of linux-plugins with native applications

OPTIONS=	FLASH	"install linux-flashplugin"	off \
		REALPLAYER	"install linux-realplayer"	off \
		ACROREAD	"install acroread7"	off

.include <bsd.port.pre.mk>

.if		 ${OSVERSION} >= 700009
IGNORE=		doesn't support ELF symbol versioning, yet.
.endif

# I will remove WITH_PLUGINS knob.
.if		defined(WITH_FLASH)
RUN_DEPENDS=	${X11BASE}/lib/linux-flashplugin6/libflashplayer.so:${PORTSDIR}/www/linux-flashplugin6
WITH_PLUGINS=	1
.endif
.if		defined(WITH_REALPLAYER)
RUN_DEPENDS+=	${X11BASE}/lib/linux-mozilla/plugins/nphelix.so:${PORTSDIR}/multimedia/linux-realplayer
WITH_PLUGINS=	1
.endif
.if		defined(WITH_ACROREAD)
RUN_DEPENDS+=	${X11BASE}/Adobe/Acrobat7.0/ENU/Browser/intellinux/nppdf.so:${PORTSDIR}/print/acroread7
WITH_PLUGINS=	1
.endif

.if		defined(WITH_PLUGINS)
.if		${OSVERSION} < 500000
USE_MOTIF=	yes
.endif
.endif

ONLY_FOR_ARCHS=	i386
MAKE_ENV=	EXAMPLESDIR=${EXAMPLESDIR} INSTALL_DATA="${INSTALL_DATA}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"

CONFLICTS=	flashpluginwrapper-*
USE_XLIB=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}
PKGMESSAGE=	${WRKDIR}/pkg-message
.if		!defined(WITH_PLUGINS) || ${OSVERSION} < 500000
PLIST=		${WRKDIR}/pkg-plist
.endif

.if		${OSVERSION} >= 700001
LIBMAPCONF=	${EXAMPLESDIR}/libmap.conf-FreeBSD6
.elif		${OSVERSION} >= 600033 && ${OSVERSION} < 700000
LIBMAPCONF=	${EXAMPLESDIR}/libmap.conf-FreeBSD6
.elif		${OSVERSION} >= 503001
LIBMAPCONF=	${EXAMPLESDIR}/libmap.conf-FreeBSD5-stable
.elif		${OSVERSION} >= 500000
LIBMAPCONF=	${EXAMPLESDIR}/libmap.conf-FreeBSD5-current
.else
LIBMAPCONF=	${EXAMPLESDIR}/libmap.conf-FreeBSD4.x
.endif

.if		${OSVERSION} < 501105
RTLD=		/usr/libexec/ld-elf.so.1
.else
RTLD=		/libexec/ld-elf.so.1
.endif

.if		defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG=1
.endif

.if		!defined(PACKAGE_BUILDING)
.if		${OSVERSION} < 490102 || ${OSVERSION} >= 500000 && ${OSVERSION} < 501107
pre-everything::
	@if ! strings ${RTLD} | ${GREP} libmap.conf > /dev/null 2>&1; then \
		${ECHO_MSG} 'Please enable libmap.conf(5) feature for rtld(1).'; \
		${ECHO_MSG} '4-stable user:'; \
		${ECHO_MSG} '	You can get a following patch.'; \
		${ECHO_MSG} '	http://people.FreeBSD.org/~nork/libmap_4stable.diff'; \
		${ECHO_MSG} '   Please apply on /usr/src and make install on /usr/src/libexec/rtld-elf:'; \
		${ECHO_MSG} '   # cd /usr/src ; patch -p0 < /tmp/libmap_4stable.diff'; \
		${ECHO_MSG} '   # cd libexec/rtld-elf ; make clean all install'; \
		${ECHO_MSG} '5.1-RELEASE user:'; \
		${ECHO_MSG} '	Please see /usr/src/libexec/rtld-elf/Makefile.'; \
		${FALSE}; \
	fi
.endif
.endif

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		-e 's,%%X11BASE%%,${X11BASE},' \
		-e 's,%%LTHREADSHMAJOR%%,${LTHREADSHMAJOR},' \
		-e 's,%%LIBMAPCONF%%,${LIBMAPCONF},' \
		< ${.CURDIR}/pkg-message > ${PKGMESSAGE}
.if		!defined(WITH_PLUGINS)
	@${SED} -e "/exec/d" ${.CURDIR}/pkg-plist > ${PLIST}
.endif

.if		defined(WITH_PLUGINS)
pre-install:
	@${MKDIR} ${X11BASE}/lib/browser_linux_plugins
.if		defined(WITH_ACROREAD)
	@${LN} -sf ${X11BASE}/Adobe/Acrobat7.0/ENU/Browser/intellinux/nppdf.so \
		${X11BASE}/lib/browser_linux_plugins/
.endif
.if		defined(WITH_FLASH)
	@${LN} -sf ${X11BASE}/lib/linux-flashplugin6/flashplayer.xpt \
		${X11BASE}/lib/browser_linux_plugins/
	@${LN} -sf ${X11BASE}/lib/linux-flashplugin6/libflashplayer.so \
		${X11BASE}/lib/browser_linux_plugins/
.endif
.if		defined(WITH_REALPLAYER)
	@${LN} -sf ${X11BASE}/lib/linux-mozilla/plugins/nphelix.so \
		${X11BASE}/lib/browser_linux_plugins/
	@${LN} -sf ${X11BASE}/lib/linux-mozilla/plugins/nphelix.xpt \
		${X11BASE}/lib/browser_linux_plugins/
.endif
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:	linuxpluginwrapper
# Date Created:				2003-06-15
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linuxpluginwrapper
PORTVERSION=	20040208
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~nork/distfiles/
MASTER_SITE_SUBDIR=	nork

MAINTAINER=	nork@FreeBSD.org
COMMENT=	A wrapper allowing use of linux-plugins with native applications

.include <bsd.port.pre.mk>

LIB_DEPENDS=	lthread.${LTHREAD_MAJOR}:${PORTSDIR}/devel/linuxthreads
RUN_DEPENDS=	${LOCALBASE}/Acrobat5/Browsers/intellinux/nppdf.so:${PORTSDIR}/print/acroread5 \
		${LOCALBASE}/lib/linux-flashplugin6/libflashplayer.so:${PORTSDIR}/www/linux-flashplugin6

ONLY_FOR_ARCHS=	i386

USE_XLIB=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFLICTS=	flashpluginwrapper-*

.if		${OSVERSION} >= 500035 && defined(LINUXTHREADS_WRAP_API)
LTHREAD_MAJOR=	5
.elif		${OSVERSION} >= 500035
LTHREAD_MAJOR=	3
.elif		${OSVERSION} <  500035 && defined(LINUXTHREADS_WRAP_API)
LTHREAD_MAJOR=	4
.elif		${OSVERSION} <  500035
LTHREAD_MAJOR=	2
.endif

.if		${OSVERSION} >= 500000
LIBMAPCONF=	${WRKSRC}/misc/libmap.conf-FreeBSD5.x
.else
LIBMAPCONF=	${WRKSRC}/misc/libmap.conf-FreeBSD4.x
.endif

.if		${OSVERSION} < 501105
RTLD=		/usr/libexec/ld-elf.so.1
.else
RTLD=		/libexec/ld-elf.so.1
.endif

.if		defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG=1
.endif

.if		(${OSVERSION} < 490102 || ${OSVERSION} >= 500000 && ${OSVERSION} < 501107) && !defined(PACKAGE_BUILDING)
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

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		-e 's,%%X11BASE%%,${X11BASE},' \
		-e 's,%%LTHREADSHMAJOR%%,${LTHREADSHMAJOR},' \
		-e '/^%%LIBMAPCONF%%$$/r ${LIBMAPCONF}' \
		-e '/^%%LIBMAPCONF%%$$/d' \
		< ${.CURDIR}/pkg-message > ${PKGMESSAGE}

pre-install:
	@${MKDIR} ${X11BASE}/lib/browser_plugins
	@${LN} -sf ${LOCALBASE}/Acrobat5/Browsers/intellinux/nppdf.so \
		${X11BASE}/lib/browser_plugins/
	@${LN} -sf ${LOCALBASE}/lib/linux-flashplugin6/flashplayer.xpt \
		${X11BASE}/lib/browser_plugins/
	@${LN} -sf ${LOCALBASE}/lib/linux-flashplugin6/libflashplayer.so \
		${X11BASE}/lib/browser_plugins/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

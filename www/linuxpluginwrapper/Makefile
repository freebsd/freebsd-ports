# New ports collection makefile for:	linuxpluginwrapper
# Date Created:				2003-06-15
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linuxpluginwrapper
PORTVERSION=	20031122
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~nork/distfiles/
MASTER_SITE_SUBDIR=	nork

MAINTAINER=	nork@FreeBSD.org
COMMENT=	A wrapper allowing use of linux-plugins with native browsers

.include <bsd.port.pre.mk>

LIB_DEPENDS=	lthread.${LTHREAD_MAJOR}:${PORTSDIR}/devel/linuxthreads
RUN_DEPENDS=	${LOCALBASE}/Acrobat5/Browsers/intellinux/nppdf.so:${PORTSDIR}/print/acroread5
RUN_DEPENDS+=	${LOCALBASE}/lib/linux-flashplugin6/libflashplayer.so:${PORTSDIR}/www/linux-flashplugin6

USE_XLIB=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386
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

.if		${OSVERSION} >= 501105
RTLD=		/libexec/ld-elf.so.1
.else
RTLD=		/usr/libexec/ld-elf.so.1
.endif

.if		defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG=1
.endif

.if		!defined(PACKAGE_BUILDING)
pre-everything::
	@if ! ${GREP} libmap.conf ${RTLD} > /dev/null 2>&1; then \
		${ECHO_MSG} 'Please enable libmap.conf(5) feature for rtld(1).'; \
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
	@${LN} -sf ${LOCALBASE}/Acrobat5/Browsers/intellinux/nppdf.so    ${X11BASE}/lib/browser_plugins/
	@${LN} -sf ${LOCALBASE}/lib/linux-flashplugin6/flashplayer.xpt   ${X11BASE}/lib/browser_plugins/
	@${LN} -sf ${LOCALBASE}/lib/linux-flashplugin6/libflashplayer.so ${X11BASE}/lib/browser_plugins/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

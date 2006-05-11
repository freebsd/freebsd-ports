# New ports collection makefile for:    nxserver
# Date created:                         Sun 5 Sep 2004
# Whom:                                 Will Andrews <will@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nxserver
PORTVERSION=	1.4.0
CATEGORIES=	net
MASTER_SITES=	${URL}/:X11 \
		${URL}/:agent \
		${URL}/:comp \
		${URL}/:compext \
		${URL}/:proxy \
		${URL}/:auth \
		${URL}/:viewer \
		${URL}/:desktop
DISTFILES=	nx-X11-1.4.0-10.tar.gz:X11 \
		nxagent-1.4.0-65.tar.gz:agent \
		nxcomp-1.4.0-31.tar.gz:comp \
		nxcompext-1.4.0-3.tar.gz:compext \
		nxproxy-1.4.0-2.tar.gz:proxy \
		nxauth-1.4.0-2.tar.gz:auth \
		nxviewer-1.4.0-4.tar.gz:viewer \
		nxdesktop-1.4.0-61.tar.gz:desktop

MAINTAINER=	freenx@deweyonline.com
COMMENT=	Low-bandwidth X network server

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	nc:${PORTSDIR}/net/netcat

URL=		http://www.nomachine.com/download/nxsources/1.4.0
WRKSRC=		${WRKDIR}
ALL_TARGET=	World
NXPREFIX?=	${PREFIX}/NX
USE_GMAKE=	yes
USE_IMAKE=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500014
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-nx-X11-programs-Xserver-hw-nxagent-Reconnect.c
.endif

.if ${OSVERSION} > 502126
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-nxcomp-types.h
.endif

do-configure:
	cd ${WRKSRC} && \
	for i in nx[cp]* ; do ( cd $$i ; ./configure "$$*" ); done && \
	(cd nxviewer ; ${XMKMF} -a)

do-build:
	cd ${WRKSRC}/nx-X11 && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
	cd ${WRKSRC}/nxcomp && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
	cd ${WRKSRC}/nxcompext && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
	cd ${WRKSRC}/nxproxy && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
	cd ${WRKSRC}/nxdesktop &&  \
		${GMAKE}
	cd ${WRKSRC}/nxviewer && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

do-install:
	${MKDIR} ${NXPREFIX}/lib ${NXPREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/nx-X11/lib/X11/libX11.so* ${NXPREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/nx-X11/lib/Xext/libXext.so* ${NXPREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/nx-X11/lib/Xrender/libXrender.so* ${NXPREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/nxcomp/libXcomp.so* ${NXPREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/nxcompext/libXcompext.so* ${NXPREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/nx-X11/programs/Xserver/nxagent ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxdesktop/nxdesktop ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxproxy/nxproxy ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxviewer/nxpasswd/nxpasswd ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxviewer/nxviewer/nxviewer ${NXPREFIX}/bin

.include <bsd.port.post.mk>

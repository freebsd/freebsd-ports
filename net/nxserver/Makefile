# New ports collection makefile for:    nxserver
# Date created:                         Sun 5 Sep 2004
# Whom:                                 Will Andrews <will@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nxserver
PORTVERSION=	2.1.0
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://web04.nomachine.com/download/${PORTVERSION}/sources/
DISTFILES=	nx-X11-${PORTVERSION}-3.tar.gz \
		nxagent-${PORTVERSION}-18.tar.gz \
		nxauth-${PORTVERSION}-2.tar.gz \
		nxcomp-${PORTVERSION}-7.tar.gz \
		nxcompext-${PORTVERSION}-5.tar.gz \
		nxdesktop-${PORTVERSION}-10.tar.gz \
		nxesd-${PORTVERSION}-3.tar.gz \
		nxkill-${PORTVERSION}-2.tar.gz \
		nxproxy-${PORTVERSION}-3.tar.gz \
		nxviewer-${PORTVERSION}-12.tar.gz
DIST_SUBDIR=	NX

MAINTAINER=	freenx@deweyonline.com
COMMENT=	Low-bandwidth X network server

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

# freetype version included does not compile on 64bit
ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
USE_GETTEXT=	yes
WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes
ALL_TARGET=	World
PLIST_SUB+=	NX_MAJOR=${PORTVERSION:R:R} NX_VERSION=${PORTVERSION}
NXPREFIX?=	${PREFIX}/NX
USE_LDCONFIG=	${NXPREFIX}/lib

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		"s|/usr/NX/bin:/opt/NX/bin:/usr/local/NX|${NXPREFIX}|" \
		${WRKSRC}/nxcomp/Children.cpp
	@${REINPLACE_CMD} -e "s|/usr/NX|${NXPREFIX}|" \
		${WRKSRC}/nxcomp/Loop.cpp \
		${WRKSRC}/nxcomp/Misc.cpp \
		${WRKSRC}/nxdesktop/xwin.c \
		${WRKSRC}/nxesd/nxesddsp.in \
		${WRKSRC}/nxviewer/nxviewer/desktop.c \
		${WRKSRC}/nx-X11/programs/Xserver/hw/nxagent/Display.c
	@${REINPLACE_CMD} -e "s|-I\.\./nxesd|-I${PREFIX}/include &|" \
		${WRKSRC}/nxdesktop/Makefile
	@${REINPLACE_CMD} -e "s|/usr/local/|${PREFIX}/|" \
		${WRKSRC}/nxviewer/nxviewer/Imakefile
	@${REINPLACE_CMD} -e "s|objformat=.*|objformat=elf|" \
		 ${WRKSRC}/nxesd/configure

do-configure:
.if defined(TEMPLATES) && exists(${TEMPLATES}/config.guess) && exists(${TEMPLATES}/config.sub)
	@CONFIG_GUESS_DIRS=$$(${FIND} ${WRKDIR} -name config.guess \
		-o -name config.sub | ${XARGS} -n 1 ${DIRNAME}); \
	for _D in $${CONFIG_GUESS_DIRS}; do \
		${CP} -f ${TEMPLATES}/config.guess $${_D}/config.guess; \
		${CHMOD} a+rx $${_D}/config.guess; \
		${CP} -f ${TEMPLATES}/config.sub $${_D}/config.sub; \
		${CHMOD} a+rx $${_D}/config.sub; \
	done
.endif

do-build:
	cd ${WRKSRC}/nx-X11 && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.for i in nxproxy nxkill nxesd
	cd ${WRKSRC}/${i} && \
		${CONFIGURE_ENV} ./configure --prefix=${NXPREFIX} && \
		${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
.endfor
	cd ${WRKSRC}/nxdesktop && ${CONFIGURE_ENV} ./configure \
		--with-sound --prefix=${NXPREFIX} && \
		${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
	cd ${WRKSRC}/nxviewer && \
		PATH=${WRKSRC}/nx-X11/config/imake:$${PATH} \
		../nx-X11/config/util/xmkmf -a ${WRKSRC}/nx-X11 && \
		${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	${MKDIR} ${NXPREFIX}/lib ${NXPREFIX}/bin ${NXPREFIX}/share/keymaps-windows
	${INSTALL_DATA} ${WRKSRC}/nx-X11/lib/X11/libX11.so.6.2 ${NXPREFIX}/lib
	cd ${NXPREFIX}/lib && \
		${LN} -s libX11.so.6.2 libX11.so.6 && \
		${LN} -s libX11.so.6.2 libX11.so
	${INSTALL_DATA} ${WRKSRC}/nx-X11/lib/Xext/libXext.so.6.4 ${NXPREFIX}/lib
	cd ${NXPREFIX}/lib && \
		${LN} -s libXext.so.6.4 libXext.so.6 && \
		${LN} -s libXext.so.6.4 libXext.so
	${INSTALL_DATA} ${WRKSRC}/nx-X11/lib/Xrender/libXrender.so.1.2 ${NXPREFIX}/lib
	cd ${NXPREFIX}/lib && \
		${LN} -s libXrender.so.1.2 libXrender.so.1 && \
		${LN} -s libXrender.so.1.2 libXrender.so
	${INSTALL_DATA} ${WRKSRC}/nx-X11/lib/Xpm/libXpm.so.4.11 ${NXPREFIX}/lib
	cd ${NXPREFIX}/lib && \
		${LN} -s libXpm.so.4.11 libXpm.so.4 && \
		${LN} -s libXpm.so.4.11 libXpm.so
	${INSTALL_DATA} ${WRKSRC}/nxcomp/libXcomp.so.${PORTVERSION} ${NXPREFIX}/lib
	cd ${NXPREFIX}/lib && \
		${LN} -s libXcomp.so.${PORTVERSION} libXcomp.so.${PORTVERSION:R:R} && \
		${LN} -s libXcomp.so.${PORTVERSION} libXcomp.so
	${INSTALL_DATA} ${WRKSRC}/nxcompext/libXcompext.so.${PORTVERSION} ${NXPREFIX}/lib
	cd ${NXPREFIX}/lib && \
		${LN} -s libXcompext.so.${PORTVERSION} libXcompext.so.${PORTVERSION:R:R} && \
		${LN} -s libXcompext.so.${PORTVERSION} libXcompext.so
	${INSTALL_PROGRAM} ${WRKSRC}/nx-X11/programs/Xserver/nxagent ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxdesktop/nxdesktop ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxesd/nxesd ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxkill/nxkill ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxproxy/nxproxy ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxviewer/nxpasswd/nxpasswd ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxviewer/nxviewer/nxviewer ${NXPREFIX}/bin
.for i in modifiers common ar cs da de de-ch en-dv en-gb en-us es et fi fo fr fr-be fr-ca fr-ch he hr hu is it ja ko lt lv mk nl nl-be no pl pt pt-br ru sl sv th tr
	${INSTALL_DATA} ${WRKSRC}/nxdesktop/keymaps/${i} ${NXPREFIX}/share/keymaps-windows
.endfor

.include <bsd.port.post.mk>

# New ports collection makefile for:	Ogle FOX GUI
# Date created:         Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	goggles
PORTVERSION=	0.8.0
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://www.fifthplanet.net/files/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A FOX frontend to the Ogle DVD player

BUILD_DEPENDS=	${LOCALBASE}/lib/ogle/libdvdcontrol.so.11:${PORTSDIR}/multimedia/ogle
LIB_DEPENDS=	FOX-1.4:${PORTSDIR}/x11-toolkits/fox14
RUN_DEPENDS=	ogle:${PORTSDIR}/multimedia/ogle

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11 xv xproto xext
MAKE_JOBS_SAFE=	yes

pre-everything::
.ifndef(WITH_DVD_DEVICE)
	@${ECHO_MSG} '===> The default DVD device is ${DEFAULT_DVD_DEVICE}'
	@${ECHO_MSG} "===> You can choose any DVD device at Ogle's command line"
	@${ECHO_MSG} '===> Define WITH_DVD_DEVICE if you want to change the default'
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

.include <bsd.port.pre.mk>

.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif

PLIST_FILES=	\
		bin/goggles \
		bin/ogle_gui_goggles
#
.ifndef(NOPORTDOCS)
PORTDOCS=	\
		goggles_manual.pdf
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/bin/bash|${SH}|' \
		-e 's|^(MAKE=).*$$|\1${GMAKE}|' \
		-e 's|function print_help|print_help|' \
		${WRKSRC}/gb
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
	    ${WRKSRC}/build/xvdetect

do-configure:
# fix dvd device
# correct applnk location
	@${REINPLACE_CMD} -E \
		-e 's|^(CONFIG_DVD_DEVICE=).+$$|\1"${DEFAULT_DVD_DEVICE}"|' \
		-e 's|applnk-mdk|applnk|' \
		${WRKSRC}/build/config.linux
# uphold PREFIX
# uphold C{,XX}FLAGS
# uphold C{C,XX}
	@${REINPLACE_CMD} -E \
		-e 's|/usr/share/|${PREFIX}/share/|' \
		-e 's|^(export[[:space:]]+CC=).+$$|\1"${CC}"|' \
		-e 's|^(export[[:space:]]+CXX=).+$$|\1"${CXX}"|' \
		-e 's|^(export[[:space:]]+CFLAGS=).+$$|\1"${CFLAGS} ${PTHREAD_CFLAGS}"|' \
		-e 's|^(export[[:space:]]+CXXFLAGS=).+$$|\1"${CXXFLAGS}"|' \
		-e 's|^(export[[:space:]]+LIBS=).+$$|\1"${PTHREAD_LIBS}"|' \
		-e 's|^(export[[:space:]]+LIBLINK=)"ar (.+)$$|\1"${AR} \2|' \
		${WRKSRC}/build/config.linux

do-build:
	@cd ${WRKSRC} && ./gb \
		--prefix=${PREFIX} \
		--fox-prefix=${LOCALBASE} \
		--ogle-prefix=${LOCALBASE} \
		--with-xv=yes

post-build:
	@${SED} -E \
		-e 's|@prefix@|${PREFIX}|' \
		${WRKSRC}/scripts/goggles.in > \
			${WRKDIR}/goggles

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/desktop/goggles_manual.pdf ${DOCSDIR}
.endif
	@${INSTALL_SCRIPT} ${WRKDIR}/goggles ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ogle_gui_goggles ${PREFIX}/bin

.include <bsd.port.post.mk>

# New ports collection makefile for:	Ogle FOX GUI
# Date created:         Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	goggles
PORTVERSION=	0.7.7
CATEGORIES=	multimedia
MASTER_SITES=	http://www.fifthplanet.net/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1//}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A FOX frontend to the Ogle DVD player

BUILD_DEPENDS=	${LOCALBASE}/lib/ogle/libdvdcontrol.so.11:${PORTSDIR}/multimedia/ogle
LIB_DEPENDS=	FOX-1.2.11:${PORTSDIR}/x11-toolkits/fox-devel
RUN_DEPENDS=	ogle:${PORTSDIR}/multimedia/ogle

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

pre-everything::
.ifndef(WITH_DVD_DEVICE)
	@${ECHO_MSG} '===> The default DVD device is ${DEFAULT_DVD_DEVICE}'
	@${ECHO_MSG} "===> You can choose any DVD device at Ogle's command line"
	@${ECHO_MSG} '===> Define WITH_DVD_DEVICE if you want to change the default'
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

.include <bsd.port.pre.mk>

#.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102
#BROKEN=		"Does not compile on alpha 5.x"
#.endif

.if ${ARCH} != "i386"
BROKEN=		"Install fails on !i386"
.endif

.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif
.endif

PLIST_BIN=	\
		bin/goggles \
		bin/ogle_gui_goggles
#
.ifndef(NOPORTDOCS)
PLIST_DOCS=	\
		goggles_manual.pdf
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|make|${GMAKE}|g' \
		-e 's|function print_help|print_help|' \
		${WRKSRC}/gb

do-configure:
	@${REINPLACE_CMD} -e 's|%%DVDDEVICE%%|${DEFAULT_DVD_DEVICE}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%X11BASE%%|${X11BASE}|g' \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%PTHREADLIBS%%|${PTHREAD_LIBS}|g' ${WRKSRC}/build/config.linux

do-build:
	@cd ${WRKSRC} && ./gb

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/desktop/goggles_manual.pdf ${DOCSDIR}
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/goggles ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ogle_gui_goggles ${PREFIX}/bin

.include <bsd.port.post.mk>

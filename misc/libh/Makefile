# New ports collection makefile for: lib
# Date Created:		19 September 2000
# Whom:			nra
#
# $FreeBSD$
#

PORTNAME=	libh
PORTVERSION=	0.2.2
CATEGORIES=	misc
MASTER_SITES=	http://rtp.freebsd.org/~libh/distfiles/

MAINTAINER=	anarcat@anarcat.ath.cx
COMMENT=	FreeBSD's next-generation sysinstall/package management tool

BROKEN=		"fails to compile due to recent changes elsewhere"

LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83 \
		tvision.0:${PORTSDIR}/devel/tvision
BUILD_DEPENDS= 	${X11BASE}/lib/libqt2.a:${PORTSDIR}/x11-toolkits/qt2-static

USE_QT_VER=	2
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

# until we find a way of including ${WRKSRC}/${PORTNAME}/Makefile.uitype
# only after "extract"
UITYPE?=	text+graphics

do-build:
	(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET} UITYPE=${UITYPE})

.include <bsd.port.mk>

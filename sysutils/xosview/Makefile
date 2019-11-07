# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	xosview
DISTVERSION=	1.21
CATEGORIES=	sysutils

MAINTAINER=	otacilio.neto@bsd.com.br
COMMENT=	Graphical performance meter

LICENSE=	BSD4CLAUSE GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	uses x86-specific hardware resources

USES=		gmake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	hills

USE_XORG=	x11 xpm
MAKE_ENV=	OPTFLAGS="" PLATFORM=bsd MANDIR=${MANPREFIX}/man
ALL_TARGET=	xosview

DESKTOP_ENTRIES="XOsview" "" "" "xosview" "" ""

do-configure:
	@${SED} -e '/CXX/s|^|#|' -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/targets/freebsd > ${WRKSRC}/.config

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CP} ${WRKSRC}/Xdefaults ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XOsview

.include <bsd.port.mk>

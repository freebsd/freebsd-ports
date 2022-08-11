PORTNAME=	xosview
DISTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	otaciliodearaujo@gmail.com
COMMENT=	Graphical performance meter

LICENSE=	BSD4CLAUSE GPLv2
LICENSE_COMB=	multi

RUN_DEPENDS=	font-misc-misc>=1.1.2:x11-fonts/font-misc-misc

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

# Created by: okeeblow <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	abgx360gui
PORTVERSION=	1.0.2
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://update.cooltrainer.org/abgx360/ \
		http://abgx360.x-scene.com/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} abgx360-256.png
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	root@cooltrainer.org
COMMENT=	wxWidgets frontend for abgx360

RUN_DEPENDS=	abgx360:${PORTSDIR}/sysutils/abgx360 \
		xterm:${PORTSDIR}/x11/xterm

PLIST_FILES=	bin/abgx360gui \
		share/pixmaps/abgx360-256.png

GNU_CONFIGURE=	yes
USE_WX=		2.8
WX_UNICODE=	yes
WX_COMPS=	wx
CONFIGURE_ARGS=	--with-wx=${LOCALBASE} \
		--with-wx-config=${WX_CONFIG:T}

DESKTOP_ENTRIES=	"abgx360" \
			"Verify and repair Xbox 360 backup images" \
			"${PREFIX}/share/pixmaps/abgx360-256.png" \
			"abgx360gui" \
			"Utility;" \
			false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abgx360gui ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/abgx360-256.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>

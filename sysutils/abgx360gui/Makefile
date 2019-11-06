# Created by: okeeblow <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	abgx360gui
PORTVERSION=	1.0.2
PORTREVISION=	9
CATEGORIES=	sysutils
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://update.cooltrainer.org/abgx360/:png \
		http://abgx360.xecuter.com/dl/ \
		http://dl.dropbox.com/u/59058148/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} abgx360-256.png:png
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	root@cooltrainer.org
COMMENT=	wxWidgets frontend for abgx360

BROKEN=		unfetchable

LICENSE=	NONE

RUN_DEPENDS=	abgx360:sysutils/abgx360 \
		xterm:x11/xterm

PLIST_FILES=	bin/abgx360gui \
		share/pixmaps/abgx360-256.png

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang
USE_WX=		2.8
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

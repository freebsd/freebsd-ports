# New ports collection makefile for:	wmproxyper
# Date created:				22 June 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmproxyper
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://home.student.utwente.nl/w.k.havinga/wmproxyper/
DISTNAME=	WMProxyPer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays Distributed.net Personal Proxy current status and progress

LIB_DEPENDS=	dockapp.1:${PORTSDIR}/x11-wm/libdockapp

PLIST_FILES=	bin/wmproxyper
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" INC=-I${X11BASE}/include \
		LIBS="-lXext -lX11 -lm -L${LOCALBASE}/lib -L${X11BASE}/lib -lXpm -ldockapp"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>

# New ports collection makefile for:	perf
# Date created:				09 March 2001
# Whom:					Tobias Begalke <tobega@spyz.org>
#
# $FreeBSD$
#

PORTNAME=	perf
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.spyz.org/perf/

MAINTAINER=	tobega@spyz.org
COMMENT=	Xview-based system monitoring tool

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

USE_IMAKE=		yes
MAN1=			perf.1
PLIST_FILES=		bin/perf
XFREE86_HTML_MAN=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/perf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/perf.1 ${PREFIX}/man/man1
	${GZIP_CMD} ${PREFIX}/man/man1/perf.1

.include <bsd.port.mk>

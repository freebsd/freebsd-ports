# New ports collection makefile for:    xdf
# Date created:                         9 November 2002
# Whom:                                 David Vidal-Rodriguez
#
# $FreeBSD$
#

PORTNAME=	xdf
PORTVERSION=    1.3
PORTREVISION=	1
CATEGORIES=     misc
MASTER_SITES=   http://home.in.tum.de/~vidalrod/ports/

MAINTAINER=     vidalrod@in.tum.de
COMMENT=	A graphical disk space viewer for X

LIB_DEPENDS=    xview.3:${PORTSDIR}/x11-toolkits/xview

PLIST_FILES=	bin/xdf
USE_XLIB=	yes
USE_X_PREFIX=   yes
USE_GMAKE=      yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/xdf

.include <bsd.port.post.mk>

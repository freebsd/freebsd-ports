# New ports collection makefile for:	asfsm
# Date created:		27 Sep 1999
# Whom:			jack
#
# $FreeBSD$
#

PORTNAME=	asmon
PORTVERSION=	0.60
CATEGORIES=	sysutils afterstep
MASTER_SITES=	ftp://ftp.afterstep.org/apps/asmon/ \
		http://www.tigr.net/afterstep/as-apps/download/asmon/

MAINTAINER=	jack@germanium.xtalwind.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400000
BROKEN=	'Sorry, asmom can not yet handle 4.0+ new VM system interfaces'
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	clean all

do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g kmem -m 2755 ${WRKSRC}/asmon/asmon ${PREFIX}/bin

.include <bsd.port.post.mk>

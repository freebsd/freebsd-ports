# New ports collection makefile for:	asclock-gtk
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asclock-gtk
PORTVERSION=	2.1.10
CATEGORIES=	x11-clocks afterstep windowmaker
MASTER_SITES=	http://www.asclock.org/tar/
DISTNAME=	${PKGNAME}beta

MAINTAINER=	kuriyama@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

WRKSRC=		${WRKDIR}/${PORTNAME}

HAS_CONFIGURE=	YES
USE_X_PREFIX=	YES
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
ALL_TARGET=	asclock

.if defined(BATCH)
do-configure:
	@(cd ${WRKSRC}; \
	  ${RM} -rf default_theme; \
	  ${LN} -s themes/classic default_theme)
.endif

post-install:
	@strip ${PREFIX}/bin/asclock

.include <bsd.port.mk>

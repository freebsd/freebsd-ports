# New ports collection makefile for:	asclock-gtk
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asclock-gtk
PORTVERSION=	2.1.10
DISTNAME=	asclock-gtk-2.1.10beta
CATEGORIES=	x11-clocks afterstep windowmaker
MASTER_SITES=	http://www.asclock.org/tar/
DISTNAME=	${PKGNAME}beta

MAINTAINER=	kuriyama@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

HAS_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/asclock-gtk
USE_X_PREFIX=	YES
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

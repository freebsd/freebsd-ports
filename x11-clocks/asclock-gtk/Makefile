# New ports collection makefile for:	asclock-gtk
# Version required:	2.1.10beta
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	asclock-gtk-2.1.10beta
PKGNAME=	asclock-gtk-beta-2.1.10
CATEGORIES=	x11-clocks afterstep windowmaker
MASTER_SITES=	http://www.asclock.org/tar/

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

# New ports collection makefile for: cheatah
# Date created:   11 June 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	cheatah
PORTVERSION=	${MAKE} -V PORTVERSION -f ${MAINDIR}/${MAKEFILE}
PORTREVISION=	${MAKE} -V PORTREVISION -f ${MAINDIR}/${MAKEFILE}
PORTEPOCH=	${MAKE} -V PORTEPOCH -f ${MAINDIR}/${MAKEFILE}
CATEGORIES=	misc
DISTFILES=

MAINTAINER=	wvengen@stack.nl

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/misc/sword:extract
LIB_DEPENDS=	sword.1:${PORTSDIR}/misc/sword
RUN_DEPENDS=	${LOCALBASE}/share/sword/mods.d:${PORTSDIR}/misc/sword-modules

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GTK=	yes

MAINDIR=	${.CURDIR}/../sword
PORTVERSION!=	${PORTVERSION}
PORTREVISION!=	${PORTREVISION}
PORTEPOCH!=	${PORTEPOCH}
WRKSRC=		${WRKDIRPREFIX}${MAINDIR}/work/sword-${PORTVERSION}/apps/X11/cheatah

post-install:
	@strip ${PREFIX}/bin/cheatah

.include <bsd.port.mk>

# New ports collection makefile for: cheatah
# Date created:   11 June 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	cheatah
PORTVERSION=	${MAKE} -V PORTVERSION -f ${MAINDIR}/${MKFILE}
PORTREVISION=	${MAKE} -V PORTREVISION -f ${MAINDIR}/${MKFILE}
PORTEPOCH=	${MAKE} -V PORTEPOCH -f ${MAINDIR}/${MKFILE}
CATEGORIES=	misc
DISTFILES=

MAINTAINER=	wvengen@stack.nl
COMMENT=	Temporary gtk GUI to the SWORD project

BROKEN=		"Does not build, will be removed after Feb 2"

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/misc/sword:extract
LIB_DEPENDS=	sword.1:${PORTSDIR}/misc/sword
RUN_DEPENDS=	${LOCALBASE}/share/sword/mods.d:${PORTSDIR}/misc/sword-modules

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12

MAINDIR=	${.CURDIR}/../sword
MKFILE!=	/usr/bin/basename ${MAKEFILE}
PORTVERSION!=	${PORTVERSION}
PORTREVISION!=	${PORTREVISION}
PORTEPOCH!=	${PORTEPOCH}
PLIST_FILES=	bin/cheatah
WRKSRC=		${WRKDIRPREFIX}${MAINDIR}/work/sword-${PORTVERSION}/apps/X11/cheatah

post-patch:
	@${CHMOD} a+x ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/cheatah

.include <bsd.port.mk>

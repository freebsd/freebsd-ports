# New ports collection makefile for:   mango
# Date created:        23 March 2001
# Whom:                Roland Jesse <jesse@cs.uni-magdeburg.de>
#
# $FreeBSD$
#

PORTNAME=	mango
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=mango

MAINTAINER=	jesse@cs.uni-magdeburg.de

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

USE_BZIP2=	yes
USE_QT_VER=	2
TMAKEENV=	TMAKEPATH=${PREFIX}/share/tmake/freebsd-g++ QTDIR=${X11BASE}
MAKE_ENV+=	QTDIR=${X11BASE}

do-build:
	(cd ${WRKSRC}; ${SETENV} ${TMAKEENV} tmake -o Makefile mango.pro)
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mango ${PREFIX}/bin

.include <bsd.port.mk>

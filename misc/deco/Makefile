# New ports collection makefile for:	deco
# Date created:				16 Dec 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	deco
PORTVERSION=	3.8.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cronyx.ru/cronyx/deco/
DISTNAME=	deco383
EXTRACT_SUFX=	.tgz

MAINTAINER=	demon@FreeBSD.org

WRKSRC=		${WRKDIR}/deco383
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
CONFIGURE_ENV=	ac_cv_lib_ncurses_tgetent=no
MAN1=		deco.1 deco-r.1

.include <bsd.port.mk>

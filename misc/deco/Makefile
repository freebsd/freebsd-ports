# New ports collection makefile for:	deco
# Version required:			3.8
# Date created:				16 Dec 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		deco383
PKGNAME=		deco-3.8.3
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.cronyx.ru/cronyx/deco/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dima@Chg.RU

WRKSRC=			${WRKDIR}/deco383
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--libdir=${PREFIX}/share
CONFIGURE_ENV=		ac_cv_lib_ncurses_tgetent=no
MAN1=			deco.1 deco-r.1

.include <bsd.port.mk>

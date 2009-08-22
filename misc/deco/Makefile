# New ports collection makefile for:	deco
# Date created:				16 Dec 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	deco
PORTVERSION=	3.9
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/Deco%20Sources/${PORTVERSION}
DISTNAME=	deco39
EXTRACT_SUFX=	.tgz

MAINTAINER=	ru@FreeBSD.org
COMMENT=	Demos Commander, a free Norton Commander clone

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
CONFIGURE_ENV=	ac_cv_lib_ncurses_tgetent=no
MAN1=		deco.1
MANLANG=	"" ru.KOI8-R

.include <bsd.port.mk>

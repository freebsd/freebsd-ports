# New ports collection makefile for:	pdmenu
# Date created:		14 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$

PORTNAME=	pdmenu
PORTVERSION=	1.2.81
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	pdmenu_${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org
COMMENT=	A simple console menu program

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/pdmenu

MAN1=		pdmenu.1
MAN5=		pdmenurc.5

CC+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib

CONFIGURE_ENV=	SLANG_LIB_LOC='${PREFIX}/lib' \
		SLANG_H_LOC='${PREFIX}/include/slang.h'

pre-install:
	${MKDIR} ${PREFIX}/lib/pdmenu
	${MKDIR} ${PREFIX}/share/pdmenu

.include <bsd.port.mk>

# New ports collection makefile for:	pdmenu
# Version required:     1.2.48
# Date created:		14 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$

DISTNAME=       pdmenu_1.2.59
PKGNAME=	pdmenu-1.2.59
CATEGORIES=	misc
MASTER_SITES=	http://kitenet.net/programs/code/pdmenu/

MAINTAINER=	nbm@FreeBSD.org

LIB_DEPENDS=    slang.1:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/pdmenu

MAN1=		pdmenu.1
MAN5=		pdmenurc.5

CONFIGURE_ENV=  SLANG_LIB_LOC='${PREFIX}/lib' \
		SLANG_H_LOC='${PREFIX}/include/slang.h'

pre-install:
	${MKDIR} ${PREFIX}/lib/pdmenu

.include <bsd.port.mk>

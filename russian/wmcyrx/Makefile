# New ports collection makefile for: CyrX-2
# Version required: 2.0
# Date created:		04 Janyary 1999
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $Id$
#

DISTNAME=       cyrx2.0
PKGNAME=	ru-wmcyrx-2.0
CATEGORIES=     russian windowmaker
MASTER_SITES=   http://yard.hitech.mipt.ru/~mini/distrib/

MAINTAINER=     ozz@FreeBSD.org.ru

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=         ${WRKDIR}/cyrx-2.0
#NO_INSTALL_MANPAGES= yes

post-extract:
	@ ${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrx2 ${PREFIX}/bin/wmcyrx2

.include <bsd.port.mk>

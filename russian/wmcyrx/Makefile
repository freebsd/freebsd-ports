# New ports collection makefile for: CyrX-2
# Date created:		04 Janyary 1999
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	wmcyrx
PORTVERSION=	2.1
CATEGORIES=     russian windowmaker
MASTER_SITES=   http://yard.hitech.mipt.ru/~mini/distrib/ \
		ftp://ftp.ssau.ru/pub/software/Linux/Cyrillic/ \
		ftp://ftp.uven.ru/pub/cyrillic/X11/keyboard/

DISTNAME=	cyrx-${PORTVERSION}

MAINTAINER=     ozz@FreeBSD.org.ru

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm

NO_INSTALL_MANPAGES= yes

post-extract:
	@ ${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrx2 ${PREFIX}/bin/wmcyrx2

.include <bsd.port.mk>

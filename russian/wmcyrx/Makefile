# New ports collection makefile for: CyrX-2
# Date created:		04 Janyary 1999
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	wmcyrx
PORTVERSION=	2.1
CATEGORIES=	russian windowmaker
MASTER_SITES=	http://freebsd.org.ru/~osa/distfiles/ \
		ftp://ftp.ssau.ru/pub/linux_soft/Cyrillic/ \
		ftp://ftp.uven.ru/pub/cyrillic/X11/keyboard/

DISTNAME=	cyrx-${PORTVERSION}

MAINTAINER=	ozz@FreeBSD.org.ru

USE_XPM=	yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400012
MAKE_ENV=	COPT="-fpermissive"
.endif

post-extract:
	@ ${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrx2 ${PREFIX}/bin/wmcyrx2

.include <bsd.port.post.mk>

# New ports collection makefile for:	ytree
# Version required:			1.65
# Date created:				5 Jan 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		ytree-1.65
CATEGORIES=		misc
#MASTER_SITES=		${MASTER_SITE_SUNSITE} \
#			http://www.han.de/~werner/
#MASTER_SITE_SUBDIR=	utils/file/managers

MAINTAINER=		ports@FreeBSD.org

ALL_TARGET=
MAN1=			ytree.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ytree ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/ytree.conf ${PREFIX}/etc/ytree.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/ytree.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ytree
.for file in CHANGES COPYING README THANKS
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ytree
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	ytree
# Version required:			1.65
# Date created:				5 Jan 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1998/11/11 12:26:00 jkoshy Exp $
#

DISTNAME=		ytree-1.65
CATEGORIES=		misc
MASTER_SITES=		http://www.han.de/~werner/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers

MAINTAINER=		andy@icc.surw.chel.su

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

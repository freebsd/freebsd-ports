# New ports collection makefile for:	ytree
# Date created:				5 Jan 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	ytree
PORTVERSION=	1.78
CATEGORIES=	misc
MASTER_SITES=	http://www.han.de/~werner/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	DOS-XTREE(tm) look-a-like file manager

ALL_TARGET=	ytree
MAN1=		ytree.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ytree ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ytree.conf ${PREFIX}/etc/ytree.conf.sample
	${INSTALL_MAN} ${WRKSRC}/ytree.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ytree
.for file in CHANGES README THANKS
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ytree
.endfor
	@if [ ! -e ${PREFIX}/etc/ytree.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/ytree.conf ${PREFIX}/etc/ytree.conf; \
	fi
.endif

.include <bsd.port.mk>

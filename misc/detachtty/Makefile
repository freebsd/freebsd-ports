# New ports collection makefile for:	detachtty
# Date created:		25 March 2003
# Whom:			johs
#
# $FreeBSD$
#

PORTNAME=	detachtty
PORTVERSION=	8
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.linux.org.uk/pub/lisp/detachtty/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	johs@copyleft.no
COMMENT=	Run interactive programs non-interactively

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes

MAN1=		detachtty.1
MLINKS=		detachtty.1 attachtty.1
MANCOMPRESSED=	no

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/detachtty.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>

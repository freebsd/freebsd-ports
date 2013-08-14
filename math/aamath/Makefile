# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	aamath
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	math textproc
MASTER_SITES=	http://fuse.superglue.se/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Renders ASCII art from mathematical expressions

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

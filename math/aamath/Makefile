# New ports collection makefile for:	aamath
# Date created:		2005-06-23
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	aamath
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	math textproc
MASTER_SITES=	http://fuse.superglue.se/aamath/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aamath is a tool for rendering mathematical expressions to ascii art

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES+=	bin/${PORTNAME}
MAN1=		aamath.1

MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
LDFLAGS=	-lreadline

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/aamath ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.include <bsd.port.mk>

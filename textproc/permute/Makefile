# New ports collection makefile for:	permute
# Date created:				Wed Aug 07 2005
# Whom:					erik@smluc.org
#
# $FreeBSD$
#

PORTNAME=	permute
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://pigseye.kennesaw.edu/~rbentley/

MAINTAINER=	erik@smluc.org
COMMENT=	Generate all permutations of lines from stdin

PLIST_FILES=	bin/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>

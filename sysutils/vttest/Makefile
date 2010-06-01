# New ports collection makefile for:	vttest
# Date created:		2005-07-21
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	vttest
PORTVERSION=	2010.05.28
CATEGORIES=	sysutils
MASTER_SITES=	ftp://invisible-island.net/vttest/
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.,,g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A program to test "VT100-compatibility" of terminals

GNU_CONFIGURE=	yes

MAKEFILE=	makefile

MAN1=		vttest.1
PLIST_FILES=	bin/vttest

.include <bsd.port.mk>

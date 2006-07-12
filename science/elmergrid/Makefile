# New ports collection makefile for:	ElmerGrid
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	elmergrid
PORTVERSION=	5.2.0
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Mesh Manipulation Utility for use with the ELMER FEM package

USE_GCC=	4.1+
GNU_CONFIGURE=	yes
ALL_TARGET=

PLIST_FILES=	bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-ElmerGrid	\
		bin/ElmerGrid

post-install:
		${LN} -sf ${PREFIX}/bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-ElmerGrid \
			${PREFIX}/bin/ElmerGrid

.include <bsd.port.mk>

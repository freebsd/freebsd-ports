# New ports collection makefile for:	mtrxmath
# Date created:				09 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		mtrxmath
PORTVERSION=		0.9.3
PORTREVISION=	1
CATEGORIES=		math
MASTER_SITES=		http://www.angelfire.com/linux/linuxjeff/mtrxmath/files/

MAINTAINER=		greid@ukug.uk.freebsd.org
COMMENT=	A small tool for matrix mathemetics

USE_GETOPT_LONG=yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtrxmath ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/README.mtrxmath

.include <bsd.port.mk>

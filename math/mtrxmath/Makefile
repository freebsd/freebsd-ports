# New ports collection makefile for:	mtrxmath
# Date created:				09 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mtrxmath
PORTVERSION=	1.0.2
CATEGORIES=	math
MASTER_SITES=	http://www.angelfire.com/linux/linuxjeff/mtrxmath/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small tool for matrix mathemetics

USE_GETOPT_LONG=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PORTDOCS=	README
PLIST_FILES=	bin/mtrxmath

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtrxmath ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

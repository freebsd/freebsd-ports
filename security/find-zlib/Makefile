# New ports collection makefile for:	find-zlib
# Date created:				2002-05-08
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	find_zlib
PORTVERSION=	1.9
CATEGORIES=	security
MASTER_SITES=	http://www.gzip.org/zlib/
DISTNAME=	find-zlib
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scans files for statically linked zlib (libz) code

PLIST_FILES=	bin/find-zlib
NO_BUILD=	none
USE_PERL5_RUN=	yes

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>

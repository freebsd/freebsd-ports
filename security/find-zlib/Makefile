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

MAINTAINER=	trevor@FreeBSD.org

PLIST=		${WRKDIR}/pkg-plist
NO_BUILD=	none
USE_PERL5=	yes

pre-install:
	${ECHO_CMD} bin/find-zlib > ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>

# New ports collection makefile for: pocketreader
# Date created: 14 April 2002
# Whom: Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	pocketreader
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	textproc linux
MASTER_SITES=	http://www.pocketreader.com/download/software/
DISTNAME=	linux-bin
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	simond@irrelevant.org
COMMENT=	Siemens PocketReader

USE_LINUX=	YES
NO_BUILD=	YES
PLIST_FILES=	bin/pocketreader

WRKSRC=		${WRKDIR}/linux

do-install:
	${BRANDELF} -t Linux ${WRKSRC}/installfiles/pocketreader_static
	${CP} ${WRKSRC}/installfiles/pocketreader_static ${PREFIX}/bin/pocketreader

.include <bsd.port.mk>

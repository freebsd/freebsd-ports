# New ports collection makefile for:		lep
# Date created:				15 May 2004
# Whom:					Dmitri Nikulin <setagllib@optusnet.com.au>
#
# $FreeBSD$
#

PORTNAME=	lep
PORTVERSION=	0.41
CATEGORIES=	security
MASTER_SITES=	http://members.optusnet.com.au/setagllib/

MAINTAINER=	setagllib@optusnet.com.au
COMMENT=	Lesser Encryption Project

USE_BZIP2=	yes
USE_OPENSSL=	yes

MAN1=		lep.1
PLIST_FILES=	bin/lep

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lep.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>

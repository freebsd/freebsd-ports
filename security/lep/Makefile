# Created by: Dmitri Nikulin <setagllib@optusnet.com.au>
# $FreeBSD$

PORTNAME=	lep
PORTVERSION=	0.41
CATEGORIES=	security
MASTER_SITES=	http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lesser Encryption Project

DEPRECATED=	No more upstream, no more public distfiles
EXPIRATION_DATE=	2013-02-27

USE_BZIP2=	yes
USE_OPENSSL=	yes

MAN1=		lep.1
PLIST_FILES=	bin/lep

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lep.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>

# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	sst
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://utcc.utoronto.ca/~pkern/stuff/sst/
DISTNAME=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Simple SSL tunneling tool (uses netcat)

.if !exists(/usr/bin/nc)
RUN_DEPENDS=	netcat:net/netcat
.endif

MAKEFILE=	${FILESDIR}/Makefile
USES=		uidfix
USE_OPENSSL=	YES

PLIST_FILES=	sbin/sst \
		man/man1/sst.1.gz

.include <bsd.port.mk>

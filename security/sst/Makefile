# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	sst
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://utcc.utoronto.ca/~pkern/stuff/sst/
DISTNAME=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A simple SSL tunneling tool (uses netcat)

.if !exists(/usr/bin/nc)
RUN_DEPENDS=	netcat:${PORTSDIR}/net/netcat
.endif

USE_OPENSSL=	YES
MAN1=		sst.1
MANCOMPRESSED=	maybe
PLIST_FILES=	sbin/sst

MAKEFILE=	${FILESDIR}/Makefile

NO_STAGE=	yes
.include <bsd.port.mk>

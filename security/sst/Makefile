PORTNAME=	sst
PORTVERSION=	1.26
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://utcc.utoronto.ca/~pkern/stuff/sst/

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Simple SSL tunneling tool (uses netcat)
WWW=		https://utcc.utoronto.ca/~pkern/stuff/sst/

.if !exists(/usr/bin/nc)
RUN_DEPENDS=	netcat:net/netcat
.endif

MAKEFILE=	${FILESDIR}/Makefile
USES=		uidfix ssl tar:xz

PLIST_FILES=	sbin/sst \
		share/man/man1/sst.1.gz

.include <bsd.port.mk>

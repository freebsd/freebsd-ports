# Created by: Dmitri Nikulin <setagllib@optusnet.com.au>
# $FreeBSD$

PORTNAME=	stress
PORTVERSION=	1.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://weather.ou.edu/~apw/projects/stress/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Tool to impose load on and stress test Unix-like systems

GNU_CONFIGURE=	yes

INFO=		stress
MAN1=		stress.1
PLIST_FILES=	bin/stress

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^\(CFLAGS\ \)=|\1 +=|; s|^\(CFLAGS.*\)-Wall|\1|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>

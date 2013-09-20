# Created by: Andrew Turner <zombie@i4free.co.nz>
# $FreeBSD$

PORTNAME=	dwatch
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://siag.nu/pub/dwatch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon Watcher

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

MAN1=		dwatch.1
PLIST_FILES=	bin/dwatch etc/dwatch.conf-dist

CFLAGS+=	-DETCDIR="\"${PREFIX}/etc\"" \
		-DPS="\"/bin/ps -ax\""

NO_STAGE=	yes
do-build:
	(cd ${BUILD_WRKSRC}; ${CC} ${CFLAGS} -o dwatch dwatch.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwatch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dwatch.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/dwatch.conf ${PREFIX}/etc/dwatch.conf-dist

.include <bsd.port.mk>

# Created by: mich@FreeBSD.org
# $FreeBSD$

PORTNAME=	rate
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://s-tech.elsat.net.pl/bmtools/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Traffic analysis command-line utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-lcompat
CFLAGS+=	-DOPEN_BSD=1 -DHAVE_REGEX -DSTREAM_ANALYZER -DIOCTL_GETWINSIZE -DAUTOSENSE_DLH

PLIST_FILES=	bin/rate man/man1/rate.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rate ${STAGEDIR}${PREFIX}/bin/rate
	${INSTALL_MAN} ${WRKSRC}/doc/rate.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

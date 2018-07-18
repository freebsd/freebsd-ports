# Created by: Douglas Fraser <doug@idmf.net>
# $FreeBSD$

PORTNAME=	grepcidr
PORTVERSION=	2.0
CATEGORIES=	net-mgmt textproc
MASTER_SITES=	http://www.pc-tools.net/files/unix/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filter IP addresses matching IPv4 CIDR/network specification

LICENSE=	GPLv2

USES=		gmake

PLIST_FILES=	bin/grepcidr \
		man/man1/grepcidr.1.gz

do-configure:
	${REINPLACE_CMD} \
		-e 's|PREFIX=.*|PREFIX=${PREFIX}|' \
		-e 's|CFLAGS=.*|CFLAGS=${CFLAGS}|' \
		-e 's|DESTDIR=.*|DESTDIR=${STAGEDIR}|' \
		-e 's|MANDIR=.*|MANDIR=${MANPREFIX}/man|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>

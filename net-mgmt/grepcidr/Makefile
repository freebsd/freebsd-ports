PORTNAME=	grepcidr
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net-mgmt textproc
MASTER_SITES=	http://www.pc-tools.net/files/unix/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filter IP addresses matching IPv4 CIDR/network specification
WWW=		http://www.pc-tools.net/unix/grepcidr/

LICENSE=	GPLv2

USES=		gmake

PLIST_FILES=	bin/grepcidr \
		share/man/man1/grepcidr.1.gz

do-configure:
	${REINPLACE_CMD} \
		-e 's|PREFIX=.*|PREFIX=${PREFIX}|' \
		-e 's|CFLAGS=.*|CFLAGS=${CFLAGS}|' \
		-e 's|DESTDIR=.*|DESTDIR=${STAGEDIR}|' \
		-e 's|MANDIR=.*|MANDIR=${PREFIX}/share/man|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>

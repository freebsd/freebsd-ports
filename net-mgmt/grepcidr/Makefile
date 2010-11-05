# New ports collection makefile for:	grepcidr
# Date created:			2005-04-24
# Whom:				Douglas Fraser <doug@idmf.net>
#
# $FreeBSD$
#

PORTNAME=	grepcidr
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	net-mgmt textproc
MASTER_SITES=	http://www.pc-tools.net/files/unix/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Filter IP addresses matching IPv4 CIDR/network specification

PLIST_FILES=	bin/grepcidr

do-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/local/bin|${PREFIX}/bin|' \
		-e 's|-s -O3 -Wall -pedantic|${CFLAGS} -DHAVE_STRING_H|' \
		-e 's|gcc|${CC}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>

# New ports collection makefile for:	grepcidr
# Date created:			2005-04-24
# Whom:				Douglas Fraser <doug@idmf.net>
#
# $FreeBSD$
#

PORTNAME=	grepcidr
PORTVERSION=	1.3
CATEGORIES=	net-mgmt textproc
MASTER_SITES=	http://www.pc-tools.net/files/unix/

MAINTAINER=	doug+ports@idmf.net
COMMENT=	Filter IP addresses matching IPv4 CIDR/network specification

PLIST_FILES=	bin/grepcidr

USE_REINPLACE= yes

do-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/local/bin|${PREFIX}/bin|' \
		-e 's|-s -O3 -Wall -pedantic|${CFLAGS}|' \
		-e 's|gcc|${CC}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>

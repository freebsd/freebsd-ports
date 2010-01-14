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
MASTER_SITES=	http://www.pc-tools.net/files/unix/

MAINTAINER=	doug+ports@idmf.net
COMMENT=	Filter IP addresses matching IPv4 CIDR/network specification

OPTIONS=	SEARCH		"Enable pattern search anywhere in line" off

PLIST_FILES=	bin/grepcidr

.include <bsd.port.pre.mk>

.if defined(WITH_SEARCH)
EXTRA_PATCHES+=	${FILESDIR}/find_anywhere.diff
.endif

do-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/local/bin|${PREFIX}/bin|' \
		-e 's|-s -O3 -Wall -pedantic|${CFLAGS} -DHAVE_STRING_H|' \
		-e 's|gcc|${CC}|' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>

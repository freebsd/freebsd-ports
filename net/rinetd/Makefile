# New ports collection makefile for:	rinetd
# Version required:			0.61
# Date created:				23 Dec 1997
# Whom:					alexp
#
# $FreeBSD$
#

DISTNAME=       rinetd
PKGNAME= 	rinetd-0.61
CATEGORIES=     net
MASTER_SITES=   ftp://ftp.boutell.com/pub/boutell/rinetd/

MAINTAINER=     veers@disturbed.net

WRKSRC=		${WRKDIR}/rinetd/

MAN8=           rinetd.8

post-install:
	${MKDIR} ${PREFIX}/share/doc/rinetd
	${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/index.html ${PREFIX}/share/doc/rinetd/
	${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/README ${PREFIX}/share/doc/rinetd/

.include <bsd.port.mk>

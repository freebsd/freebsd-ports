# New ports collection makefile for:   surfraw
# Date created:                2000-08-03
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	surfraw
PORTVERSION=	1.0.7
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/proff/ \
		ftp://ftp.funet.fi/pub/NetBSD/misc/proff/

MAINTAINER=	naddy@FreeBSD.org

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/examples/surfraw
	${INSTALL_DATA} ${WRKSRC}/surfraw.conf ${PREFIX}/share/examples/surfraw
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

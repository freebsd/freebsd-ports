# New ports collection makefile for:   surfraw
# Date created:                2000-08-03
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	surfraw
PORTVERSION=	1.0.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_NETBSD}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line interface to popular WWW search engines

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/examples/surfraw
	${INSTALL_DATA} ${WRKSRC}/surfraw.conf ${PREFIX}/share/examples/surfraw
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

# New ports collection makefile for:    subweb
# Date created:                         december 30, 2001
# Whom: 				Nicolas Jombart <Nicolas.Jombart@hsc-labs.com>
#
# $FreeBSD$
#

PORTNAME=	subweb
PORTVERSION=	1.0
CATEGORIES=	security www
MASTER_SITES=	http://www.hsc.fr/ressources/outils/subweb/download/

MAINTAINER=	ecu@ipv42.net
COMMENT=	SubWeb is a (reverse) proxy to inspect HTTP flows on the fly

NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/subweb ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/subweb
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/subweb
.endif

.include <bsd.port.mk>

# New ports collection makefile for: 	sgrep
# Date created:    			Apr 29 1998
# Whom: 				<koshy@india.hp.com>
#
# $FreeBSD$
#

PORTNAME=	sgrep
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.helsinki.fi/pub/Software/Local/Sgrep/

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A `grep' for structured text like SGML and HTML

CONFLICT=	sgrep2

MAN1=		sgrep.1

# Override the install target in the supplied makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sgrep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sgrep.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/sample.sgreprc ${PREFIX}/share/sgreprc

.include <bsd.port.mk>

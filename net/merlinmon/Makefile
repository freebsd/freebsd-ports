# Ports collection makefile for:  merlin
# Date created:			  13 Dec 1999
# Whom:				  Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	merlinmon
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kfu.com/pub/
DISTNAME=	merlin-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nsayer@freebsd.org

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/merlin ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.merlin
.endif

.include <bsd.port.mk>

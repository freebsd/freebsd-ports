# Ports collection makefile for:  merlin
# Version required:		  1.0
# Date created:			  13 Dec 1999
# Whom:				  Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	merlin-1.0
PKGNAME=	merlinmon-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kfu.com/pub/
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

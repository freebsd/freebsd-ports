# Ports collection makefile for:  merlin
# Date created:			  13 Dec 1999
# Whom:				  Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	merlinmon
PORTVERSION=	1.1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nsayer
DISTNAME=	merlin-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@freebsd.org

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/merlin ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.merlin
.endif

.include <bsd.port.mk>

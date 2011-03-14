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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A curses app that displays the status of a Novatel CDPD modem device

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/merlin ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

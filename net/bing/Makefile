# New ports collection makefile for:	bing
# Date created:		28 December 1996
# Whom:			jseger@scds.com
#
# $FreeBSD$
#

PORTNAME=	bing
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.freebsdbrasil.com.br/~jmelo/ \
		ftp://ftp.ens.fr/pub/unix/syst/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A point-to-point bandwith measurement tool

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN8=		bing.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bing ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bing.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

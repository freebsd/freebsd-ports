# New ports collection makefile for:	DeleGate
# Date created:			26 Jan 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	delegate
PORTVERSION=	7.1.2
CATEGORIES=	net www
MASTER_SITES=	ftp://ftp.delegate.org/pub/DeleGate/ \
		ftp://ftp.etl.go.jp/pub/DeleGate/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	max@FreeBSD.org

IS_INTERACTIVE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/share/examples/delegate
	${INSTALL_DATA} ${FILESDIR}/delegated.sh \
	   ${PREFIX}/share/examples/delegate
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/delegate
	${INSTALL_DATA} ${WRKSRC}/doc/Manual.htm \
	  ${PREFIX}/share/doc/delegate
.endif

.include <bsd.port.mk>

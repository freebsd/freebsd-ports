# ex:ts=8
# Ports collection makefile for:  slurpie
# Date created:			  Sun Feb 12, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	slurpie
PORTVERSION=	2.0b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/distfiles/ \
		http://people.FreeBSD.org/~foxfair/distfiles/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A passwd file cracker (supports distributed nodes)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slurp ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/slurpie ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/slurpie
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/slurpie/README
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	identify
# Date created:		13 March 1999
# Whom:			nsayer@quack.kfu.com
#
# $FreeBSD$
#

PORTNAME=	identify
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/tools/

MAINTAINER=	nsayer@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libident.a:${PORTSDIR}/security/libident

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/identify ${PREFIX}/libexec
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/identify
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/identify
.endif

.include <bsd.port.mk>

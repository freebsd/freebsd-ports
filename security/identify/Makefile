# New ports collection makefile for:	identify
# Date created:		13 March 1999
# Whom:			nsayer@quack.kfu.com
#
# $FreeBSD$
#

PORTNAME=	identify
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://www.scn.rain.com/pub/security/authent/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client side ident protocol daemon wrapper

BUILD_DEPENDS=	${LOCALBASE}/lib/libident.a:${PORTSDIR}/security/libident

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/identify ${PREFIX}/libexec
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/identify
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/identify
.endif

.include <bsd.port.mk>

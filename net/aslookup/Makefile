# New ports collection makefile for:	aslookup
# Date created:				12.04.2002
# Whom:					janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	aslookup
PORTVERSION=	0.12
CATEGORIES=	net
MASTER_SITES=	http://www.kk.iij4u.or.jp/~kuniaki/aslookup/
DISTNAME=	aslookup-alpha${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aslookup ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@if [ ! -d ${PREFIX}/share/doc/aslookup ]; then 	\
		${MKDIR} ${PREFIX}/share/doc/aslookup; fi
	${INSTALL_DATA} ${WRKSRC}/readme-eng.txt ${WRKSRC}/readme-jp.txt   \
		${PREFIX}/share/doc/aslookup
.endif

.include <bsd.port.mk>

# New ports collection makefile for:    IPv6socket_scrub
# Date created:         22.03.2002
# Whom: Janos Mohacsi <janos.mohacsi@dante.org.uk>
#
# $FreeBSD$

PORTNAME=	ipv6socket_scrub
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net devel ipv6
MASTER_SITES=	#http://www.sun.com/download/index.jsp?cat=Operating%20Systems&tab=3
DISTNAME=	IPv6socket_scrub
EXTRACT_SUFX=	.tar

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Checks IPv6 portability of C source code

WRKSRC=		${WRKDIR}/${DISTNAME}/src
RESTRICTED=	not redistributable, license agreement required

MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	Copyright README

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		needs you to sign the agreement on "http://www.sun.com/download/index.jsp?cat=Operating%20Systems&tab=3", download it manually, place in ${DISTDIR} and then restart this build
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../Docs/man/man1/${PORTNAME}.1 \
		${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>

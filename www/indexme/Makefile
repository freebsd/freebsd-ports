# New ports collection makefile for:	indexme
# Date created:		30 Jan 2000
# Whom:			Carl Johan Madestrand
#
# $FreeBSD$
#

PORTNAME=	indexme
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://users.uk.freebsd.org/pub/lord_cj/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Links files into a HTML index for viewing and easy overview

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/indexme
NO_BUILD=	yes
	     
.if !defined(NO_INSTALL_MANPAGES)
MAN1=		indexme.1
.endif

PLIST_FILES=	bin/indexme

do-install:
		@ ${INSTALL_SCRIPT} ${WRKSRC}/indexme ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
		@ ${INSTALL_MAN} ${WRKSRC}/indexme.1 ${PREFIX}/man/man1
.endif
.include <bsd.port.mk>

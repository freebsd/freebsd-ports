# New ports collection makefile for:	webredirect
# Date created:		24 October 2000
# Whom:			kaj@Raditex.se
#
# $FreeBSD$
#

PORTNAME=	webredirect
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.stacken.kth.se/pub/projects/webredirect/

MAINTAINER=	rasmus@kaj.se

ALL_TARGET=	depend all

MAN1=		webredirect.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

pre-build:
	@${TOUCH} ${WRKSRC}/incu/depend.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webredirect ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webredirect.1 ${PREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:	dtach
# Date created:		21 Jun 2004
# Whom:			Bjorn Lindstrom <bkhl@elektrubadur.se>
#
# $FreeBSD$
#

PORTNAME=		dtach
PORTVERSION=		0.8
PORTREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		SF

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Emulates the detach feature of screen

GNU_CONFIGURE=	yes
ALL_TARGET=	dtach

MAN1=		dtach.1
PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dtach ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/dtach.1 ${MAN1PREFIX}/man/man1/

.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

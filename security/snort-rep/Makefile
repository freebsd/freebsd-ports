# New ports collection makefile for:	snort-rep
# Date created:			Jul 19, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	snort-rep
PORTVERSION=	1.7
CATEGORIES=	security
MASTER_SITES=	http://people.ee.ethz.ch/~dws/software/snort-rep/pub/

MAINTAINER=	markp@FreeBSD.org

USE_PERL=	yes
MAN1=		snort-rep.1

post-patch:
	@${PERL} -pi -e "s|#!/usr/bin/perl|#!${PERL}|" \
		${WRKSRC}/snort-rep ${WRKSRC}/snort-rep-mail

do-build:
	cd ${BUILD_WRKSRC} ; pod2man --lax snort-rep > snort-rep.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snort-rep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/snort-rep.1 ${MAN1PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/examples/snort-rep
	${INSTALL_SCRIPT} ${WRKSRC}/snort-rep-mail \
		${PREFIX}/share/examples/snort-rep

.include <bsd.port.mk>

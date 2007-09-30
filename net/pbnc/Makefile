# Ports collection makefile for:  pbnc
# Date created:	  03 Apr 2004
# Whom:		  hrs
#
# $FreeBSD$

PORTNAME=	pbnc
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://duncanthrax.net/pbnc/
DISTNAME=	pbnc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Simple userspace TCP port bouncer

RUN_DEPENDS=	${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask

NO_BUILD=	yes
USE_PERL5_RUN=	yes
PLIST_FILES=	etc/pbnc.cfg bin/pbnc.pl
PORTDOCS= 	pbnc.readme

pre-install:
	${REINPLACE_CMD} 's,^#!/usr/bin/perl,#!${PERL},' ${WRKSRC}/pbnc.pl

do-install:
	${INSTALL_DATA} ${WRKSRC}/pbnc.cfg ${PREFIX}/etc/pbnc.cfg
	${INSTALL_SCRIPT} ${WRKSRC}/pbnc.pl ${PREFIX}/bin/pbnc.pl
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

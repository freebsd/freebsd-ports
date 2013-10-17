# $FreeBSD$

PORTNAME=	pbnc
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://duncanthrax.net/pbnc/
DISTNAME=	pbnc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Simple userspace TCP port bouncer

LICENSE=	BSD

RUN_DEPENDS=	p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
PLIST_FILES=	etc/pbnc.cfg bin/pbnc.pl
PORTDOCS= 	pbnc.readme

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-install:
	${REINPLACE_CMD} 's,^#!/usr/bin/perl,#!${PERL},' ${WRKSRC}/pbnc.pl

do-install:
	${INSTALL_DATA} ${WRKSRC}/pbnc.cfg ${STAGEDIR}${PREFIX}/etc/pbnc.cfg
	${INSTALL_SCRIPT} ${WRKSRC}/pbnc.pl ${STAGEDIR}${PREFIX}/bin/pbnc.pl

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

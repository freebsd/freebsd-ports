# New ports collection makefile for:	p5-Danga-Socket
# Date created:		2005-08-08
# Whom:			Jacques Marneweck <jacques@php.net>
#
# $FreeBSD$
#

PORTNAME=	Perlbal
PORTVERSION=	1.70
CATEGORIES=	www
MASTER_SITES=	http://www.danga.com/dist/Perlbal/ \
		http://www.powertrip.co.za/distfiles/danga/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reverse-proxy load balancer and webserver

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/BSD/Resource.pm:${PORTSDIR}/devel/p5-BSD-Resource \
		${SITE_PERL}/Danga/Socket.pm:${PORTSDIR}/devel/p5-Danga-Socket \
		${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		perlbal.1
MAN3=		Perlbal.3 Perlbal::Plugin::Palimg.3 \
		Perlbal::Plugin::Cgilike.3 \
		Perlbal::Plugin::Include.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif

post-install:
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

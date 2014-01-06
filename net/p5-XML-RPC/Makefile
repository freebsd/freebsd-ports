# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	XML-RPC
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Pure Perl implementation for an XML-RPC client and server

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-TreePP>=0:${PORTSDIR}/textproc/p5-XML-TreePP
RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-TreePP>=0:${PORTSDIR}/textproc/p5-XML-TreePP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

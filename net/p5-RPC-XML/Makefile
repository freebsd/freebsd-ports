# Created by: Dominic Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	RPC-XML
PORTVERSION=	0.77
PORTREVISION=	1
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML-RPC client and server library for Perl

BUILD_DEPENDS=	p5-XML-Parser>=2.31:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=5.834:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake perl5
USE_PERL5=	configure

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	CGI::Cookie::Splitter
# Created by: ijliao
# $FreeBSD$

PORTNAME=	CGI-Cookie-Splitter
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Split big cookies into smaller ones

BUILD_DEPENDS=	p5-CGI-Simple>=0:${PORTSDIR}/www/p5-CGI-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

MAN3=	CGI::Cookie::Splitter.3

.include <bsd.port.mk>

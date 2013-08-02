# New ports collection makefile for:    CGI::Builder
# Date created:                         20 Oct 2004
# Whom:                                 Daniel Wijnands <daniel@itxl.nl>
#
# $FreeBSD$
#

PORTNAME=	CGI-Builder
PORTVERSION=	1.36
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module intended to make it easier to create reusable web apps

BUILD_DEPENDS=	p5-IO-Util>=0:${PORTSDIR}/devel/p5-IO-Util \
		p5-OOTools>=0:${PORTSDIR}/devel/p5-OOTools
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Bundle::CGI::Builder::Complete.3 \
	CGI::Builder.3 \
	CGI::Builder::Conf.3 \
	CGI::Builder::Const.3 \
	CGI::Builder::Test.3

.include <bsd.port.mk>

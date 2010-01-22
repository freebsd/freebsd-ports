# New ports collection makefile for:	p5-Net-POP3-SSLWrapper
# Date created:				16 December 2009
# Whom:					johnpupu <johnpupu@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-POP3-SSLWrapper
PORTVERSION=	0.02
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Perl extension for simple POP3S wrapper for Net::POP3

RUN_DEPENDS=	p5-IO-Socket-SSL>0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-ExtUtils-MakeMaker>0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::POP3::SSLWrapper.3

.include <bsd.port.mk>

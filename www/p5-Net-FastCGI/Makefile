# New ports collection makefile for:	Net::FastCGI
# Date created:		02 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FastCGI
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHANSEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for FastCGI Toolkit

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-HexString>=0:${PORTSDIR}/devel/p5-Test-HexString

PERL_CONFIGURE=	yes

MAN3=	Net::FastCGI.3 \
	Net::FastCGI::Constant.3 \
	Net::FastCGI::IO.3 \
	Net::FastCGI::Protocol.3

.include <bsd.port.mk>

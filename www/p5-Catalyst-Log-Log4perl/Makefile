# New ports collection makefile for:	www/p5-Catalyst-Log-Log4perl
# Date created:				Jan 11 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Log-Log4perl
PORTVERSION=	1.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log::Log4perl logging for Catalyst

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Log-Log4perl>=0.49:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Catalyst::Log::Log4perl.3

.include <bsd.port.mk>

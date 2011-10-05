# New ports collection makefile for:	www/p5-Catalyst-Log-Log4perl
# Date created:				Jan 11 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Log-Log4perl
PORTVERSION=	1.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log::Log4perl logging for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.6000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Log-Log4perl>=1.04:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	Use Log::Log4perl::Catalyst (devel/p5-Log-Log4perl) instead.
EXPIRATION_DATE=	2011-11-05

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Log::Log4perl.3

.include <bsd.port.mk>

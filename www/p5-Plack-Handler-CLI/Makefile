# New ports collection makefile for:	Plack::Handler::CLI
# Date created:		06 Aug 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Handler-CLI
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for command line interface to PSGI applications

RUN_DEPENDS=	\
	p5-Any-Moose>0:${PORTSDIR}/devel/p5-Any-Moose \
	p5-Plack>=0.99:${PORTSDIR}/www/p5-Plack \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Handler::CLI.3

.include <bsd.port.mk>

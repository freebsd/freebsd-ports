# New ports collection makefile for:	POEx::Role::PSGIServer
# Date created:		09 Oct 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POEx-Role-PSGIServer
PORTVERSION=	1.102531
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/F/FR/FRODWITH
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for encapsulated PSGI server behaviors for POE

RUN_DEPENDS=	\
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Moose-Autobox>0:${PORTSDIR}/devel/p5-Moose-Autobox \
	p5-MooseX-Declare>0:${PORTSDIR}/devel/p5-MooseX-Declare \
	p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-MooseX-Types-Structured>0:${PORTSDIR}/devel/p5-MooseX-Types-Structured \
	p5-POE-Filter-HTTP-Parser>0:${PORTSDIR}/www/p5-POE-Filter-HTTP-Parser \
	p5-POE>0:${PORTSDIR}/devel/p5-POE \
	p5-POEx-Role-Streaming>0:${PORTSDIR}/devel/p5-POEx-Role-Streaming \
	p5-POEx-Role-TCPServer>0:${PORTSDIR}/net/p5-POEx-Role-TCPServer \
	p5-POEx-Types>0:${PORTSDIR}/devel/p5-POEx-Types \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-aliased>0:${PORTSDIR}/devel/p5-aliased
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POEx::Role::PSGIServer.3 \
	POEx::Role::PSGIServer::ProxyWriter.3 \
	POEx::Role::PSGIServer::Streamer.3 \
	POEx::Types::PSGIServer.3

.include <bsd.port.mk>

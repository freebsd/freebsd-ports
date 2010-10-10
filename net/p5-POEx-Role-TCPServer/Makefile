# New ports collection makefile for:	POEx::Role::TCPServer
# Date created:		10 Oct 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POEx-Role-TCPServer
PORTVERSION=	1.102740
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NP/NPEREZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for TCPServer Moose role on POE

RUN_DEPENDS=	\
	p5-MooseX-Declare>0:${PORTSDIR}/devel/p5-MooseX-Declare \
	p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-MooseX-Types-Structured>0:${PORTSDIR}/devel/p5-MooseX-Types-Structured \
	p5-POE>0:${PORTSDIR}/devel/p5-POE \
	p5-POEx-Role-SessionInstantiation>0:${PORTSDIR}/devel/p5-POEx-Role-SessionInstantiation \
	p5-POEx-Types>0:${PORTSDIR}/devel/p5-POEx-Types \
	p5-aliased>0:${PORTSDIR}/devel/p5-aliased
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POEx::Role::TCPServer.3

.include <bsd.port.mk>

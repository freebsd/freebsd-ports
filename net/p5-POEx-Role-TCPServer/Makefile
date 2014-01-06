# $FreeBSD$

PORTNAME=	POEx-Role-TCPServer
PORTVERSION=	1.102740
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NPEREZ
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
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

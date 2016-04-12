# $FreeBSD$

PORTNAME=	POEx-Role-PSGIServer
PORTVERSION=	1.110670
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FRODWITH
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for encapsulated PSGI server behaviors for POE

RUN_DEPENDS=	\
	p5-Plack>0:www/p5-Plack \
	p5-libwww>0:www/p5-libwww \
	p5-Moose-Autobox>0:devel/p5-Moose-Autobox \
	p5-MooseX-Declare>0:devel/p5-MooseX-Declare \
	p5-MooseX-Types>0:devel/p5-MooseX-Types \
	p5-MooseX-Types-Structured>0:devel/p5-MooseX-Types-Structured \
	p5-POE-Filter-HTTP-Parser>=1.06:www/p5-POE-Filter-HTTP-Parser \
	p5-POE>0:devel/p5-POE \
	p5-POEx-Role-Streaming>0:devel/p5-POEx-Role-Streaming \
	p5-POEx-Role-TCPServer>=1.102740:net/p5-POEx-Role-TCPServer \
	p5-POEx-Types>0:devel/p5-POEx-Types \
	p5-Plack>0:www/p5-Plack \
	p5-aliased>0:devel/p5-aliased
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-HTTP-Parser-XS>=0:www/p5-HTTP-Parser-XS \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-TCP>=0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

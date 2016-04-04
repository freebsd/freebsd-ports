# $FreeBSD$

PORTNAME=	CGI-Compile
PORTVERSION=	0.19
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to compile .cgi scripts to a code reference

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-File-pushd>0:devel/p5-File-pushd
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-NoWarnings>0:devel/p5-Test-NoWarnings \
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-CGI-Emulate-PSGI>0:www/p5-CGI-Emulate-PSGI
# Depending on Plack::Test causes cyclic dependencies.

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	YES

.include <bsd.port.mk>

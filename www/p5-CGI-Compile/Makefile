# New ports collection makefile for:	CGI::Compile
# Date created:		02 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Compile
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to compile .cgi scripts to a code reference

RUN_DEPENDS=	\
	p5-File-pushd>0:${PORTSDIR}/devel/p5-File-pushd
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-NoWarnings>0:${PORTSDIR}/devel/p5-Test-NoWarnings \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN3=	CGI::Compile.3

.include <bsd.port.mk>

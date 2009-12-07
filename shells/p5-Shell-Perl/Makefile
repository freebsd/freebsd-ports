# New ports collection makefile for:	p5-Shell-Perl
# Date created:				2008-02-27
# Whom:	      				Shinsuke Matsui <smatsui@karashi.org>
#
# $FreeBSD$
#

PORTNAME=	Shell-Perl
PORTVERSION=	0.0018
PORTREVISION=	1
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	smatsui@karashi.org
COMMENT=	A read-eval-print loop in Perl

RUN_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/Data/Dump.pm:${PORTSDIR}/devel/p5-Data-Dump \
		${SITE_PERL}/${PERL_ARCH}/Data/Dump/Streamer.pm:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir
BUILD_DEPENDS=	${SITE_PERL}/Test/Script.pm:${PORTSDIR}/devel/p5-Test-Script \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		${SITE_PERL}/Test/Expect.pm:${PORTSDIR}/devel/p5-Test-Expect

PERL_CONFIGURE=	YES

MAN1=		pirl.1
MAN3=		Shell::Perl.3 Shell::Perl::Dumper.3

.include <bsd.port.mk>

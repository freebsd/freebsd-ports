# Created by: Shinsuke Matsui <smatsui@karashi.org>
# $FreeBSD$

PORTNAME=	Shell-Perl
PORTVERSION=	0.0022
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	smatsui@karashi.org
COMMENT=	A read-eval-print loop in Perl

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Data-Dump-Streamer>=0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir
BUILD_DEPENDS=	p5-Test-Script>=0:${PORTSDIR}/devel/p5-Test-Script \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Expect>=0:${PORTSDIR}/devel/p5-Test-Expect

USES=		perl5
USE_PERL5=	configure

MAN1=		pirl.1
MAN3=		Shell::Perl.3 Shell::Perl::Dumper.3

NO_STAGE=	yes
.include <bsd.port.mk>

# Created by: Shinsuke Matsui <smatsui@karashi.org>
# $FreeBSD$

PORTNAME=	Shell-Perl
PORTVERSION=	0.0022
PORTREVISION=	1
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	smatsui@karashi.org
COMMENT=	Read-eval-print loop in Perl

RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-YAML>=0:textproc/p5-YAML \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Data-Dump-Streamer>=0:devel/p5-Data-Dump-Streamer \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir
BUILD_DEPENDS=	p5-Test-Script>=0:devel/p5-Test-Script \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \
		p5-Test-Expect>=0:devel/p5-Test-Expect

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

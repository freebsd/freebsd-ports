# Created by: BluePex Security Solutions <freebsd-ports@bluepex.com>
# $FreeBSD$

PORTNAME=	Daemon-Generic
PORTVERSION=	0.84
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Framework to provide start/stop/reload for a daemon

BUILD_DEPENDS=	p5-File-Flock>=0:devel/p5-File-Flock \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Event>=0:devel/p5-Event \
		p5-Eval-LineNumbers>=0:devel/p5-Eval-LineNumbers
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

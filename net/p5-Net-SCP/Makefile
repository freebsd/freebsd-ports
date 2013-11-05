# Created by: Erich Zigler <erich@tacni.net>
# $FreeBSD$

PORTNAME=	Net-SCP
PORTVERSION=	0.08
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to access and use scp protocol

BUILD_DEPENDS=	p5-Net-SSH>=0:${PORTSDIR}/net/p5-Net-SSH \
		p5-String-ShellQuote>=0:${PORTSDIR}/textproc/p5-String-ShellQuote \
		p5-IO>=0:${PORTSDIR}/devel/p5-IO
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

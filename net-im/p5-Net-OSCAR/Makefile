# Created by: Kelly Cochran <kcochran@trolans.net>
# $FreeBSD$

PORTNAME=	Net-OSCAR
PORTVERSION=	1.928
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the AOL Instant Messenger OSCAR protocol

BUILD_DEPENDS=	p5-SOCKS>=0:net/p5-Socks \
		p5-XML-Parser>=0:textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

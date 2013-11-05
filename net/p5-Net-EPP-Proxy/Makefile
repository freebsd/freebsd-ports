# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-EPP-Proxy
PORTVERSION=	0.04
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Proxy server for the EPP protocol

BUILD_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-IO-Multiplex>=0:${PORTSDIR}/devel/p5-IO-Multiplex \
		p5-Net-EPP>=0.03:${PORTSDIR}/net/p5-Net-EPP \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

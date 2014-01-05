# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-EPP
PORTVERSION=	0.19
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Client library for the TCP transport for EPP

BUILD_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-Digest-SHA1>=2.12:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-Digest-SHA1>=2.12:${PORTSDIR}/security/p5-Digest-SHA1

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

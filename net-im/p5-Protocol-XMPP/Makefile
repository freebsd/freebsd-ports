# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	Protocol-XMPP
PORTVERSION=	0.005
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Protocol-level support for XMPP interaction

RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-XML-LibXML-SAX-ChunkParser>=0.00003:${PORTSDIR}/textproc/p5-XML-LibXML-SAX-ChunkParser

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

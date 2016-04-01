# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-XMPP2
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implementation of the XMPP Protocol

BUILD_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-BS-Event>=0:devel/p5-BS-Event \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-LibIDN>=0:dns/p5-Net-LibIDN \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-Object-Event>=0:devel/p5-Object-Event \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-Writer>=0:textproc/p5-XML-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

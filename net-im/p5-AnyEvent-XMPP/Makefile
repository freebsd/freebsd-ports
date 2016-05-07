# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AnyEvent-XMPP
PORTVERSION=	0.55
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implementation of the XMPP Protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Net-LibIDN>=0:dns/p5-Net-LibIDN \
		p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-Writer>=0:textproc/p5-XML-Writer \
		p5-Object-Event>=0.7:devel/p5-Object-Event
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

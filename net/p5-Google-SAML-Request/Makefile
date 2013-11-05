# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Google-SAML-Request
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create or parse Google\'s SAML requests

BUILD_DEPENDS=	p5-TimeDate>0:${PORTSDIR}/devel/p5-TimeDate \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	HTTP-Response-Encoding
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Adds encoding() to HTTP::Response

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-Encode>=2.0:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

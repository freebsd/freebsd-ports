# Created by: Conor McDermottroe <ports@mcdermottroe.com>
# $FreeBSD$

PORTNAME=	TestGen4Web-Runner
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/WWW/MACKERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	eg@fbsd.lt
COMMENT=	Perl module to replay files recorded with TestGen4Web

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-XML-Simple>=0:textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

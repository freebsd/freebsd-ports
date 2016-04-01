# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Amazon-EC2
PORTVERSION=	0.31
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl interface to the Amazon Elastic Compute Cloud

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Moose>=0.38:devel/p5-Moose \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-XML-Simple>=2.18:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww \
		p5-Test-Exception>=0.31:devel/p5-Test-Exception
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>

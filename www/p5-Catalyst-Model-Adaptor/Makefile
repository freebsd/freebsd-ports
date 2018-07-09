# Created by: Vladimir Timofeev <vovkasm@gmail.com>
# $FreeBSD$

PORTNAME=	Catalyst-Model-Adaptor
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Use a plain class as a Catalyst model

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=0:www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat
TEST_DEPENDS=	p5-Test-WWW-Mechanize-Catalyst>=0:devel/p5-Test-WWW-Mechanize-Catalyst

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

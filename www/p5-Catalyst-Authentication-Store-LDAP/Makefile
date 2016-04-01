# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Catalyst-Authentication-Store-LDAP
PORTVERSION=	1.016
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Authentication from an LDAP Directory for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Plugin-Authentication>=0.10003:www/p5-Catalyst-Plugin-Authentication \
		p5-perl-ldap>=0:net/p5-perl-ldap
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Net-LDAP-Server-Test>=0:net/p5-Net-LDAP-Server-Test \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Catalyst-Model-LDAP>=0:www/p5-Catalyst-Model-LDAP \
		p5-Test-MockObject>=0:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

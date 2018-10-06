# Created by: <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Interchange6
PORTVERSION=	0.203
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dancer2 Plugin for Interchange6 Open Source Shop Machine

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Interchange6-Schema>=0:databases/p5-Interchange6-Schema \
		p5-Interchange6>=0:www/p5-Interchange6 \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=2.000000:devel/p5-Moo \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-MooX-HandlesVia>=0:devel/p5-MooX-HandlesVia \
		p5-MooseX-CoverableModifiers>=0:devel/p5-MooseX-CoverableModifiers \
		p5-Net-HTTPS-Any>=0.11:net/p5-Net-HTTPS-Any \
		p5-Business-OnlinePayment>=3.04:finance/p5-Business-OnlinePayment \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-YAML>=0.86:textproc/p5-YAML \
		p5-Dancer2>=0.200002:www/p5-Dancer2 \
		p5-Dancer2-Session-DBIC>=0.102:databases/p5-Dancer2-Session-DBIC \
		p5-Dancer2-Plugin-DBIC>=0.0013:databases/p5-Dancer2-Plugin-DBIC \
		p5-Dancer2-Plugin-Auth-Extensible>=0.600:security/p5-Dancer2-Plugin-Auth-Extensible \
		p5-Dancer2-Plugin-Auth-Extensible-Provider-DBIC>=0.600:security/p5-Dancer2-Plugin-Auth-Extensible-Provider-DBIC
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBIx-Class-Helpers>=0:databases/p5-DBIx-Class-Helpers \
		p5-Test-WWW-Mechanize-PSGI>=0:devel/p5-Test-WWW-Mechanize-PSGI

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

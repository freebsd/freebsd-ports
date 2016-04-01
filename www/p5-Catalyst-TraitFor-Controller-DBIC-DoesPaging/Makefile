# Created by: Alex Bakhtin <Alex.Bakhtin@gmail.com>
# $FreeBSD$

PORTNAME=	Catalyst-TraitFor-Controller-DBIC-DoesPaging
PORTVERSION=	1.001000
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Alex.Bakhtin@gmail.com
COMMENT=	Helps you paginate, search, sort, and more easily using DBIx::Class

BUILD_DEPENDS=	p5-Catalyst-Model-DBIC-Schema>=0.29:www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-Runtime>=5.80000:www/p5-Catalyst-Runtime \
		p5-DBIx-Class>=0.08108:databases/p5-DBIx-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Catalyst-View-JSON>=0:www/p5-Catalyst-View-JSON \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-JSON>=0:converters/p5-JSON \
		p5-SQL-Translator>=0:databases/p5-SQL-Translator \
		p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

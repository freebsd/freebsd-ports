# Created by: Oleg Mamontov <oleg@mamontov.net>
# $FreeBSD$

PORTNAME=	HTML-FormFu-Model-DBIC
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Integrate HTML::FormFu with DBIx::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBIx-Class>=0.08108:databases/p5-DBIx-Class \
		p5-HTML-FormFu>=2.00:www/p5-HTML-FormFu \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DateTime-Format-SQLite>=0:devel/p5-DateTime-Format-SQLite \
		p5-Locale-Maketext>=0:devel/p5-Locale-Maketext \
		p5-SQL-Translator>=0.11016:databases/p5-SQL-Translator

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

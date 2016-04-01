# $FreeBSD$

PORTNAME=	Search-QueryParser-SQL
PORTVERSION=	0.010
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jeremybbaggs@gmail.com
COMMENT=	Perl module to turn free-text queries into SQL WHERE clauses

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Search-QueryParser>=0.93:textproc/p5-Search-QueryParser

RUN_DEPENDS:=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Search-QueryParser>=0.93:textproc/p5-Search-QueryParser

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	Search-QueryParser-SQL
PORTVERSION=	0.010
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Turn free-text queries into SQL WHERE clauses

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Search-QueryParser>=0.93:textproc/p5-Search-QueryParser

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

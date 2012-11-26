# Created by: pauls@utdallas.edu
# $FreeBSD$

PORTNAME=	Parse-Range
PORTVERSION=	0.96
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLER
PKGNAMEPREFIX=	p5-

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Parses range definitions and returns an array

LICENSE=	ART10 BSD
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build>=0.4:${PORTSDIR}/devel/p5-Module-Build \
		p5-ExtUtils-MakeMaker>=6.6:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-List-MoreUtils>=0.3:${PORTSDIR}/lang/p5-List-MoreUtils

RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Parse::Range.3

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>

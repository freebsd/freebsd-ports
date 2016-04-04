# $FreeBSD$

PORTNAME=	Text-CSV-Simple
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for Simpler parsing of CSV files

BUILD_DEPENDS=	p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Class-Trigger>=0:devel/p5-Class-Trigger
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

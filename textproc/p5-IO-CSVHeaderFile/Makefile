# Created by: Vasek Balcar <vasek@ti.cz>
# $FreeBSD$

PORTNAME=	IO-CSVHeaderFile
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to automate reads from CSV formatted text files

BUILD_DEPENDS=	p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

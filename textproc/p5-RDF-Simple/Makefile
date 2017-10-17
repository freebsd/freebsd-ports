# Created by: Aaron Straup Cope <ascope@cpan.org>
# $FreeBSD$

PORTNAME=	RDF-Simple
PORTVERSION=	0.415
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write RDF without complication

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-MakeMethods>=0:devel/p5-Class-MakeMethods \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-URI>=0:net/p5-URI \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-CaptureOutput>0:devel/p5-IO-CaptureOutput \
		p5-Test-File>=0:devel/p5-Test-File

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

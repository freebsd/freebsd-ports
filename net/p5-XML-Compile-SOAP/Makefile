# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	XML-Compile-SOAP
PORTVERSION=	3.21
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base-class for SOAP implementations

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Slurp-Tiny>=0:devel/p5-File-Slurp-Tiny \
		p5-Log-Report>=1.05:devel/p5-Log-Report \
		p5-XML-Compile>=1.51:textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=1.03:textproc/p5-XML-Compile-Cache \
		p5-libwww>=6.08:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-XML-Compile-Tester>=0.90:devel/p5-XML-Compile-Tester

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

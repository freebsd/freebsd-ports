# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	XML-Compile-SOAP
PORTVERSION=	3.26
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Base-class for SOAP implementations

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-Log-Report>=1.05:devel/p5-Log-Report \
		p5-Net-HTTP>=6.16:net/p5-Net-HTTP \
		p5-XML-Compile>=1.58:textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=1.03:textproc/p5-XML-Compile-Cache \
		p5-libwww>=6.08:www/p5-libwww
TEST_DEPENDS=	p5-XML-Compile-Tester>=0.90:devel/p5-XML-Compile-Tester

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

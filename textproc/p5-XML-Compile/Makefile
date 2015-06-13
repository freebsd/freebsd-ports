# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	XML-Compile
PORTVERSION=	1.49
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compilation based XML processing

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Report>=1.03:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-LibXML>=2.0100:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0.095:${PORTSDIR}/devel/p5-Test-Deep \
		p5-XML-Compile-Tester>=0.90:${PORTSDIR}/devel/p5-XML-Compile-Tester

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

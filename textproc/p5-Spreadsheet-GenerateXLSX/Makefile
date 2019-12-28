# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Spreadsheet-GenerateXLSX
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate XLSX spreadsheet from array ref(s)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Excel-Writer-XLSX>=0:textproc/p5-Excel-Writer-XLSX \
		p5-Ref-Util>=0:devel/p5-Ref-Util
TEST_DEPENDS=	p5-Test-Needs>=0:devel/p5-Test-Needs \
		p5-Test-Warn>=0.36:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

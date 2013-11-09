# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Excel-Writer-XLSX
PORTVERSION=	0.73
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JMCNAMARA
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create a new file in the Excel 2007+ XLSX format

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Zip>=1.30:${PORTSDIR}/archivers/p5-Archive-Zip
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>

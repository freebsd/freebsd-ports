# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	HTML-Format
PORTVERSION=	2.12
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NIGELM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module to format HTML to text or PS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Font-AFM>=0:x11-fonts/p5-Font-AFM \
		p5-HTML-Tree>=3.15:www/p5-HTML-Tree
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-Test-CPAN-Meta>=0:devel/p5-Test-CPAN-Meta \
		p5-Test-EOL>=0:devel/p5-Test-EOL \
		p5-Test-NoTabs>=0:devel/p5-Test-NoTabs

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild
#INSTALL_TARGET=	pure_install

.include <bsd.port.mk>

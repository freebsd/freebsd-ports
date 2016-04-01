# Created by: clive
# $FreeBSD$

PORTNAME=	Template-Toolkit
PORTVERSION=	2.26
PORTREVISION=	1
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN \
		http://www.template-toolkit.org/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensive Toolkit for template processing

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AppConfig>=1.56:devel/p5-AppConfig
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-Pod-POM>=0:textproc/p5-Pod-POM

OPTIONS_DEFINE=	DATE_CALC IMAGE_INFO IMAGE_SIZE POD_POM
DATE_CALC_DESC=		With Date::Calc Plugin
IMAGE_INFO_DESC=	With Image::Info Plugin
IMAGE_SIZE_DESC=	With Image::Size Plugin
POD_POM_DESC=		With Pod::POM Plugin

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	TT_ACCEPT=y

DATE_CALC_BUILD_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc
DATE_CALC_RUN_DEPENDS=		p5-Date-Calc>=0:devel/p5-Date-Calc

IMAGE_INFO_BUILD_DEPENDS=	p5-Image-Info>=0:graphics/p5-Image-Info
IMAGE_INFO_RUN_DEPENDS=		p5-Image-Info>=0:graphics/p5-Image-Info

IMAGE_SIZE_BUILD_DEPENDS=	p5-Image-Size>=0:graphics/p5-Image-Size
IMAGE_SIZE_RUN_DEPENDS=		p5-Image-Size>=0:graphics/p5-Image-Size

POD_POM_BUILD_DEPENDS=	p5-Pod-POM>=0:textproc/p5-Pod-POM
POD_POM_RUN_DEPENDS=	p5-Pod-POM>=0:textproc/p5-Pod-POM

post-patch:
	@${REINPLACE_CMD} -e '/PREFIX/ s|/usr/local|${PREFIX}/share|' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Template/Stash/XS/XS.so

.include <bsd.port.mk>

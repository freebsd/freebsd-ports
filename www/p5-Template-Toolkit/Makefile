# Created by: clive
# $FreeBSD$

PORTNAME=	Template-Toolkit
PORTVERSION=	3.008
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Extensible template processing system

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AppConfig>=1.56:devel/p5-AppConfig
TEST_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-Date-Calc>=0:devel/p5-Date-Calc \
		p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-Pod-POM>=0:textproc/p5-Pod-POM

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	TT_ACCEPT=y

OPTIONS_DEFINE=	DATE_CALC IMAGE_INFO IMAGE_SIZE POD_POM
DATE_CALC_DESC=	Time/date formatting plugin (Date::Calc)
IMAGE_INFO_DESC=Image stats plugin (Image::Info)
IMAGE_SIZE_DESC=Image size plugin (Image::Size)
POD_POM_DESC=	POD-parsing plugin (Pod::POM)

DATE_CALC_BUILD_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc
DATE_CALC_RUN_DEPENDS=		p5-Date-Calc>=0:devel/p5-Date-Calc

IMAGE_INFO_BUILD_DEPENDS=	p5-Image-Info>=0:graphics/p5-Image-Info
IMAGE_INFO_RUN_DEPENDS=		p5-Image-Info>=0:graphics/p5-Image-Info

IMAGE_SIZE_BUILD_DEPENDS=	p5-Image-Size>=0:graphics/p5-Image-Size
IMAGE_SIZE_RUN_DEPENDS=		p5-Image-Size>=0:graphics/p5-Image-Size

POD_POM_BUILD_DEPENDS=		p5-Pod-POM>=0:textproc/p5-Pod-POM
POD_POM_RUN_DEPENDS=		p5-Pod-POM>=0:textproc/p5-Pod-POM

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Template/Stash/XS/XS.so

.include <bsd.port.mk>

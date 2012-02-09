# New ports collection makefile for:	p5-Template-Toolkit
# Date Created:				3 Mar, 2001
# Whom:					clive
#
# $FreeBSD$
#

PORTNAME=	Template-Toolkit
PORTVERSION=	2.24
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN \
		http://www.template-toolkit.org/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensive Toolkit for template processing

BUILD_DEPENDS=	p5-AppConfig>=1.56:${PORTSDIR}/devel/p5-AppConfig
RUN_DEPENDS=	p5-AppConfig>=1.56:${PORTSDIR}/devel/p5-AppConfig

TEST_DEPENDS=	p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-Pod-POM>=0:${PORTSDIR}/textproc/p5-Pod-POM

OPTIONS=	DATE_CALC	"With Date::Calc Plugin"	off \
		IMAGE_INFO	"With Image::Info Plugin"	off \
		IMAGE_SIZE	"With Image::Size Plugin"	off \
		POD_POM		"With Pod::POM Plugin"		off

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	TT_ACCEPT=y

.include "Makefile.man"

.include <bsd.port.options.mk>

.if defined(WITH_DATE_CALC)
BUILD_DEPENDS+=	p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc
RUN_DEPENDS+=	p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc
.endif

.if defined(WITH_IMAGE_INFO)
BUILD_DEPENDS+=	p5-Image-Info>=0:${PORTSDIR}/graphics/p5-Image-Info
RUN_DEPENDS+=	p5-Image-Info>=0:${PORTSDIR}/graphics/p5-Image-Info
.endif

.if defined(WITH_IMAGE_SIZE)
BUILD_DEPENDS+=	p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size
RUN_DEPENDS+=	p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size
.endif

.if defined(WITH_POD_POM)
BUILD_DEPENDS+=	p5-Pod-POM>=0:${PORTSDIR}/textproc/p5-Pod-POM
RUN_DEPENDS+=	p5-Pod-POM>=0:${PORTSDIR}/textproc/p5-Pod-POM
.endif

post-patch:
	@${REINPLACE_CMD} -e '/PREFIX/ s|/usr/local|${PREFIX}/share|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>

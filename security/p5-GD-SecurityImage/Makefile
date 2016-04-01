# Created by: ports@rbt.ca
# $FreeBSD$

PORTNAME=	GD-SecurityImage
PORTVERSION=	1.73
PORTEPOCH=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for creating CAPTCHA security images

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-GD>=0:graphics/p5-GD
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	IMAGEMAGICK X11
OPTIONS_DEFAULT=X11
IMAGEMAGICK_DESC=	Build ImageMagick module

PORTSCOUT=	skipv:1.581

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
.if ${PORT_OPTIONS:MX11}
IMAGEMAGICK_BUILD_DEPENDS= ${LOCALBASE}/bin/convert:graphics/ImageMagick
IMAGEMAGICK_RUN_DEPENDS=   ${LOCALBASE}/bin/convert:graphics/ImageMagick
.else
IMAGEMAGICK_BUILD_DEPENDS= ${LOCALBASE}/bin/convert:graphics/ImageMagick-nox11
IMAGEMAGICK_RUN_DEPENDS=   ${LOCALBASE}/bin/convert:graphics/ImageMagick-nox11
.endif
.endif

.include <bsd.port.mk>

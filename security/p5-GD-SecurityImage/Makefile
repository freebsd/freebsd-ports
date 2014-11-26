# Created by: ports@rbt.ca
# $FreeBSD$

PORTNAME=	GD-SecurityImage
PORTVERSION=	1.72
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for creating CAPTCHA security images

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	IMAGEMAGICK
IMAGEMAGICK_DESC=	Build ImageMagick module

PORTSCOUT=	skipv:1.581

USES=		perl5
USE_PERL5=	configure

IMAGEMAGICK_BUILD_DEPENDS=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
IMAGEMAGICK_RUN_DEPENDS=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick

.include <bsd.port.mk>

# New ports collection makefile for:	GD-SecurityImage
# Date created:				15 October 2005
# Whom:					ports@rbt.ca
#
# $FreeBSD$
#

PORTNAME=	GD-SecurityImage
PORTVERSION=	1.71
PORTEPOCH=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for creating CAPTCHA security images

BUILD_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD

OPTIONS_DEFINE=	IMAGEMAGICK
IMAGEMAGICK_DESC=	Build ImageMagick module

PORTSCOUT=	skipv:1.581

PERL_CONFIGURE=	yes

MAN3=		GD::SecurityImage.3 \
		GD::SecurityImage::GD.3 \
		GD::SecurityImage::Magick.3 \
		GD::SecurityImage::Styles.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Module-Build>=0.3800:${PORTSDIR}/devel/p5-Module-Build
.endif

.include <bsd.port.post.mk>

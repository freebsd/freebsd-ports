# New ports collection makefile for:	GD-SecurityImage
# Date created:				15 October 2005
# Whom:					ports@rbt.ca
#
# $FreeBSD$
#

PORTNAME=	GD-SecurityImage
PORTVERSION=	1.70
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for creating CAPTCHA security images

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		GD::SecurityImage.3 \
		GD::SecurityImage::GD.3 \
		GD::SecurityImage::Magick.3 \
		GD::SecurityImage::Styles.3

.include <bsd.port.mk>

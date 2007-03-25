# New ports collection makefile for:	GD-SecurityImage
# Date created:				15 October 2005
# Whom:					ports@rbt.ca
#
# $FreeBSD$
#

PORTNAME=	GD-SecurityImage
PORTVERSION=	1.63
PORTEPOCH=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8, and try again
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:   p5-Image-Delivery
# Date created:                                08 September 2007
# Whom:                                        TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Delivery
PORTVERSION=	0.13
CATEGORIES=	www graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Efficient transformation and delivery of web images

BUILD_DEPENDS=	p5-Digest-MD5>=2.36:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-TransformPath>=1.00:${PORTSDIR}/devel/p5-Digest-TransformPath \
		p5-HTML-Location>=1.01:${PORTSDIR}/www/p5-HTML-Location \
		p5-File-Remove>=0.37:${PORTSDIR}/devel/p5-File-Remove \
		p5-File-Slurp>=9999.12:${PORTSDIR}/devel/p5-File-Slurp \
		p5-PathTools>=3.25:${PORTSDIR}/devel/p5-PathTools \
		p5-Scalar-List-Utils>=1.19:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Params-Coerce>=0.14:${PORTSDIR}/devel/p5-Params-Coerce
RUN_DEPENDS=	p5-Digest-MD5>=2.36:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-TransformPath>=1.00:${PORTSDIR}/devel/p5-Digest-TransformPath \
		p5-HTML-Location>=1.01:${PORTSDIR}/www/p5-HTML-Location \
		p5-File-Remove>=0.37:${PORTSDIR}/devel/p5-File-Remove \
		p5-File-Slurp>=9999.12:${PORTSDIR}/devel/p5-File-Slurp \
		p5-PathTools>=3.25:${PORTSDIR}/devel/p5-PathTools \
		p5-Scalar-List-Utils>=1.19:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Params-Coerce>=0.14:${PORTSDIR}/devel/p5-Params-Coerce

PERL_CONFIGURE=	yes

MAN3=		Image::Delivery.3 Image::Delivery::Provider.3

.include <bsd.port.mk>

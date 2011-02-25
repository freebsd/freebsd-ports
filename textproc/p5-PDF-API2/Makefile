# ex:ts=8
# Ports collection makefile for:	p5-PDF-API2
# Date created:			Feb 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	PDF-API2
PORTVERSION=	2.018
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/SS/SSIMMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	'The Next Generation' of Text::PDF::API

RUN_DEPENDS=	p5-Font-TTF>0:${PORTSDIR}/x11-fonts/p5-Font-TTF

PERL_CONFIGURE=	5.8.0+

MAN3=	PDF::API2.3 \
	PDF::API2::Annotation.3 \
	PDF::API2::Basic::PDF::Array.3 \
	PDF::API2::Basic::PDF::Bool.3 \
	PDF::API2::Basic::PDF::Dict.3 \
	PDF::API2::Basic::PDF::File.3 \
	PDF::API2::Basic::PDF::Filter.3 \
	PDF::API2::Basic::PDF::Name.3 \
	PDF::API2::Basic::PDF::Null.3 \
	PDF::API2::Basic::PDF::Number.3 \
	PDF::API2::Basic::PDF::Objind.3 \
	PDF::API2::Basic::PDF::Page.3 \
	PDF::API2::Basic::PDF::Pages.3 \
	PDF::API2::Basic::PDF::String.3 \
	PDF::API2::Basic::PDF::Utils.3 \
	PDF::API2::Content.3 \
	PDF::API2::Lite.3 \
	PDF::API2::NamedDestination.3 \
	PDF::API2::Outline.3 \
	PDF::API2::Page.3 \
	PDF::API2::Resource.3 \
	PDF::API2::Resource::BaseFont.3 \
	PDF::API2::Resource::CIDFont.3 \
	PDF::API2::Resource::CIDFont::CJKFont.3 \
	PDF::API2::Resource::CIDFont::TrueType.3 \
	PDF::API2::Resource::ColorSpace.3 \
	PDF::API2::Resource::ColorSpace::Indexed::ACTFile.3 \
	PDF::API2::Resource::ColorSpace::Separation.3 \
	PDF::API2::Resource::ExtGState.3 \
	PDF::API2::Resource::Font.3 \
	PDF::API2::Resource::Font::BdFont.3 \
	PDF::API2::Resource::Font::CoreFont.3 \
	PDF::API2::Resource::Font::SynFont.3 \
	PDF::API2::Resource::UniFont.3 \
	PDF::API2::Resource::XObject.3 \
	PDF::API2::Resource::XObject::Form.3 \
	PDF::API2::Resource::XObject::Form::BarCode.3 \
	PDF::API2::Resource::XObject::Form::BarCode::code128.3 \
	PDF::API2::Resource::XObject::Image.3 \
	PDF::API2::Resource::XObject::Image::TIFF.3 \
	PDF::API2::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
BUILD_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>

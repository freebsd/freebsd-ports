# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	FLV-Info
PORTVERSION=	0.24
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CDOLAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract metadata from Flash Video files

BUILD_DEPENDS=	p5-AMF-Perl>=0.15:${PORTSDIR}/www/p5-AMF-Perl \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-SWF-File>=0.033:${PORTSDIR}/graphics/p5-SWF-File
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		flv2mp3.1 flvinfo.1 swf2flv.1 flv2swf.1 flv2flv.1
MAN3=		FLV::File.3 \
		FLV::VideoTag.3 \
		FLV::AMFReader.3 \
		FLV::FromSWF.3 \
		FLV::Header.3 \
		FLV::Info.3 \
		FLV::ToMP3.3 \
		FLV::MetaTag.3 \
		FLV::Util.3 \
		FLV::ToSWF.3 \
		FLV::Cut.3 \
		FLV::AMFWriter.3 \
		FLV::Base.3 \
		FLV::Body.3 \
		FLV::Tag.3 \
		FLV::AudioTag.3 \
		FLV::Splice.3

.include <bsd.port.mk>

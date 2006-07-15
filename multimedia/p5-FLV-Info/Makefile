# New ports collection makefile for:	p5-FLV-Info
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	FLV-Info
PORTVERSION=	0.03
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLOTHO
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@gslin.org
COMMENT=	Extract metadata from Flash Video files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/AMF/Perl.pm:${PORTSDIR}/www/p5-AMF-Perl \
		${SITE_PERL}/SWF/File.pm:${PORTSDIR}/graphics/p5-SWF-File
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		flvinfo.1 swf2flv.1
MAN3=		FLV::AMFReader.3 FLV::AMFWriter.3 FLV::AudioTag.3 \
		FLV::Base.3 FLV::Body.3 FLV::Constants.3 FLV::File.3 \
		FLV::FromSWF.3 FLV::Header.3 FLV::Info.3 FLV::MetaTag.3 \
	       	FLV::Tag.3 FLV::VideoTag.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from graphics/p5-SWF-File
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 then try again
.endif

.if ${PERL_LEVEL} < 500702
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>

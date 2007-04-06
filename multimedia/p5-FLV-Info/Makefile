# New ports collection makefile for:	p5-FLV-Info
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	FLV-Info
PORTVERSION=	0.18
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CD/CDOLAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract metadata from Flash Video files

RUN_DEPENDS=	p5-AMF-Perl>=0.15:${PORTSDIR}/www/p5-AMF-Perl \
		p5-Digest-MD5>=2:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-SWF-File>=0.033:${PORTSDIR}/graphics/p5-SWF-File
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		flv2mp3.1 flv2flv.1 flv2swf.1 flvinfo.1 swf2flv.1
MAN3=		FLV::AMFReader.3 FLV::AMFWriter.3 FLV::AudioTag.3 \
		FLV::Base.3 FLV::Body.3 FLV::Util.3 FLV::File.3 \
		FLV::FromSWF.3 FLV::Header.3 FLV::Info.3 FLV::MetaTag.3 \
	       	FLV::Tag.3 FLV::ToMP3.3 FLV::ToSWF.3 FLV::VideoTag.3

# the dependency of Readonly was removed since 0.12, however,
# the author forget to update Makefile.PL and Build.PL correspondingly
post-patch:
	${REINPLACE_CMD} -e '/Readonly/d' ${WRKSRC}/*.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>

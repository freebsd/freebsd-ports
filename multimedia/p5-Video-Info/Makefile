# ex:ts=8
# Ports collection makefile for:	p5-Video-Info
# Date Created:			Feb 25, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Video-Info
PORTVERSION=	0.993
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Video
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Retrieve video properties such as: height width codec fps

BUILD_DEPENDS=	${SITE_PERL}/Class/MakeMethods/Emulator.pm:${PORTSDIR}/devel/p5-Class-MakeMethods \
		${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/Video/OpenQuicktime.pm:${PORTSDIR}/multimedia/p5-Video-OpenQuicktime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Video::Info.3 \
	Video::Info::ASF.3 \
	Video::Info::FOO.3 \
	Video::Info::MPEG.3 \
	Video::Info::MPEG::Audio.3 \
	Video::Info::MPEG::Constants.3 \
	Video::Info::MPEG::System.3 \
	Video::Info::MPEG::Video.3 \
	Video::Info::Magic.3 \
	Video::Info::Quicktime.3 \
	Video::Info::RIFF.3

.include <bsd.port.mk>

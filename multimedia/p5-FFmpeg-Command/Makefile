# Created by: sumikawa
# $FreeBSD$

PORTNAME=	FFmpeg-Command
PORTVERSION=	0.19
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIZZY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Wrapper class for ffmpeg command line utility

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-ErrorHandler>=0:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

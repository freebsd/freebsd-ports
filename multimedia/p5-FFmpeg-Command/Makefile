# New ports collection makefile for:	p5-FFmpeg-Command
# Date created:		2006-08-24
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	FFmpeg-Command
PORTVERSION=	0.13
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIZZY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A wrapper class for ffmpeg command line utility

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-ErrorHandler>=0:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		FFmpeg::Command.3

.include <bsd.port.mk>

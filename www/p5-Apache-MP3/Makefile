# New ports collection makefile for:	p5-Apache-MP3
# Date created:		23-Jan-2001
# Whom:			Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-MP3
PORTVERSION=	4.00
CATEGORIES=	www audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	MP3 browsing and streaming under mod_perl and Apache

BUILD_DEPENDS=	${SITE_PERL}/Audio/Wav.pm:${PORTSDIR}/audio/p5-Audio-Wav \
		${SITE_PERL}/CGI/Session.pm:${PORTSDIR}/www/p5-CGI-Session \
		${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/Ogg/Vorbis/Header.pm:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header \
		${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Apache::MP3.3 \
		Apache::MP3::L10N.3 \
		Apache::MP3::Playlist.3 \
		Apache::MP3::Resample.3 \
		Apache::MP3::Sorted.3

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/apache_mp3/* ${DATADIR}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

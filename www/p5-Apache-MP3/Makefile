# New ports collection makefile for:	p5-Apache-MP3
# Date created:		23-Jan-2001
# Whom:			Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-MP3
PORTVERSION=	3.05
CATEGORIES=	www audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	dom@happygiraffe.net
COMMENT=	MP3 browsing and streaming under mod_perl and Apache

BUILD_DEPENDS=	${SITE_PERL}/Audio/Wav.pm:${PORTSDIR}/audio/p5-Audio-Wav \
		${SITE_PERL}/MPEG/MP3Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/Ogg/Vorbis.pm:${PORTSDIR}/audio/p5-libvorbis
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext
RUN_DEPENDS+=	${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext
.endif

.if defined(WITH_APACHE2)
BROKEN=		Broken due the new mod_perl2 API
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
EXTRA_PATCHES=	${PATCHDIR}/mod_perl2.patch
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif

.include <bsd.port.post.mk>

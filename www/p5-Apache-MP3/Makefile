# Created by: Dominic Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	Apache-MP3
PORTVERSION=	4.00
PORTREVISION=	1
CATEGORIES=	www audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MP3 browsing and streaming under mod_perl and Apache

BUILD_DEPENDS=	p5-Audio-Wav>=0:${PORTSDIR}/audio/p5-Audio-Wav \
		p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
		p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info \
		p5-Ogg-Vorbis-Header>=0:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_APACHE=	22+

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

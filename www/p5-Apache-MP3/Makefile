# New ports collection makefile for:	p5-Apache-MP3
# Date created:		23-Jan-2001
# Whom:			Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-MP3
PORTVERSION=	2.15
CATEGORIES=	www audio
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	dom@happygiraffe.net

BUILD_DEPENDS=	${SITE_PERL}/MPEG/MP3Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::MP3.3 \
		Apache::MP3::Playlist.3 \
		Apache::MP3::Sorted.3

PKGDATADIR=	${PREFIX}/share/${PORTNAME}
post-install:
	${MKDIR} ${PKGDATADIR}
	${INSTALL_DATA} ${WRKSRC}/apache_mp3/* ${PKGDATADIR}

.include <bsd.port.mk>

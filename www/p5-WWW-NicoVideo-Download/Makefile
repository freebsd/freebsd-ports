# New ports collection makefile for:	p5-WWW-Nicovideo-Download
# Date created:		2009-03-03
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-NicoVideo-Download
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Perl module of download FLV/MP4/SWF files from nicovideo.jp

RUN_DEPENDS=	${SITE_PERL}/Any/Moose.pm:${PORTSDIR}/devel/p5-Any-Moose \
		${SITE_PERL}/CGI/Simple.pm:${PORTSDIR}/www/p5-CGI-Simple \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	5.8.0+

MAN3=		WWW::NicoVideo::Download.3

.include <bsd.port.mk>

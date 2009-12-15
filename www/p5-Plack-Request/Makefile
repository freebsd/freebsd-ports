# New ports collection makefile for:	Plack::Request
# Date created:		13 Oct 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Request
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for portable HTTP request object from PSGI env hash

RUN_DEPENDS=	\
	p5-CGI-Simple>0:${PORTSDIR}/www/p5-CGI-Simple \
	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-HTTP-Body>=1.05:${PORTSDIR}/www/p5-HTTP-Body \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Request.3 \
	Plack::Request::Upload.3 \
	Plack::Response.3

.include <bsd.port.mk>

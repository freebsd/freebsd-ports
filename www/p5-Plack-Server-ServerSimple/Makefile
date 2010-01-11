# New ports collection makefile for:	Plack::Server::ServerSimple
# Date created:		13 Oct 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Server-ServerSimple
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Plack Server w/ HTTP::Server::Simple

RUN_DEPENDS=	\
	p5-HTTP-Server-Simple>=0.41:${PORTSDIR}/www/p5-HTTP-Server-Simple \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Server::ServerSimple.3

.include <bsd.port.mk>

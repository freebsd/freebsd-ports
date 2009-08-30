# New ports collection makefile for:	WWW::Mechanize::Cached
# Date created:		31 Aug 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize-Cached
PORTVERSION=	1.33
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to cache esponse to be polite

RUN_DEPENDS=	\
	p5-Cache-Cache>=1.02:${PORTSDIR}/devel/p5-Cache-Cache \
	p5-Test-Warn>=0.11:${PORTSDIR}/devel/p5-Test-Warn \
	p5-WWW-Mechanize>=1.00:${PORTSDIR}/www/p5-WWW-Mechanize
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	WWW::Mechanize::Cached.3

.include <bsd.port.mk>

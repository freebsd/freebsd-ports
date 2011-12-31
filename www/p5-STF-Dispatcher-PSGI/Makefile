# New ports collection makefile for:	STF::Dispatcher::PSGI
# Date created:		31 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	STF-Dispatcher-PSGI
PORTVERSION=	1.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for pluggable STF dispatcher interface

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-HTTP-Date>0:${PORTSDIR}/www/p5-HTTP-Date \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-Plack-Middleware-Header>0:${PORTSDIR}/www/p5-Plack-Middleware-Header
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	STF::Dispatcher::Impl::File.3 \
	STF::Dispatcher::Impl::Hash.3 \
	STF::Dispatcher::PSGI.3 \
	STF::Dispatcher::PSGI::HTTPException.3 \
	STF::Dispatcher::Test.3

.include <bsd.port.mk>

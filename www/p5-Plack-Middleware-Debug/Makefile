# New ports collection makefile for:	Plack::Middleware::Debug
# Date created:		03 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-Debug
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to display information about current request/response

RUN_DEPENDS=	\
	p5-Class-Method-Modifiers>=1.05:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
	p5-Data-Dump>0:${PORTSDIR}/devel/p5-Data-Dump \
	p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-Text-MicroTemplate>=0.15:${PORTSDIR}/textproc/p5-Text-MicroTemplate \
	p5-Module-Versions>=0.01:${PORTSDIR}/devel/p5-Module-Versions
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Middleware::Debug.3 \
	Plack::Middleware::Debug::Base.3 \
	Plack::Middleware::Debug::CatalystLog.3 \
	Plack::Middleware::Debug::DBITrace.3 \
	Plack::Middleware::Debug::Environment.3 \
	Plack::Middleware::Debug::Memory.3 \
	Plack::Middleware::Debug::ModuleVersions.3 \
	Plack::Middleware::Debug::Parameters.3 \
	Plack::Middleware::Debug::PerlConfig.3 \
	Plack::Middleware::Debug::Response.3 \
	Plack::Middleware::Debug::Session.3 \
	Plack::Middleware::Debug::Timer.3 \
	Plack::Middleware::Debug::TrackObjects.3

.include <bsd.port.mk>

# New ports collection makefile for:	www/p5-Continuity
# Date created:				07 July 2008
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Continuity
PORTVERSION=	1.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/A/AW/AWWAIID
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Stateful Web applications in Perl

BUILD_DEPENDS=	p5-Event>0:${PORTSDIR}/devel/p5-Event \
		p5-Coro>=4.37:${PORTSDIR}/devel/p5-Coro \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Continuity.3 \
	Continuity::Adapt::FCGI.3 \
	Continuity::Adapt::HttpDaemon.3 \
	Continuity::Inspector.3 \
	Continuity::Mapper.3 \
	Continuity::Request.3 \
	Continuity::RequestCallbacks.3

.include <bsd.port.mk>

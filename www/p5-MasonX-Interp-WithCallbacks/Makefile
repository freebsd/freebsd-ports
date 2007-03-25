# New ports collection makefile for:	p5-MasonX-Interp-WithCallbacks
# Date created:			May 21, 2004
# Whom:				Rod Taylor <ports@rbt.ca>
#
# $FreeBSD$
#

PORTNAME=	MasonX-Interp-WithCallbacks
PORTVERSION=	1.16
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MasonX/DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mason callback support via Params::CallbackRequest

BUILD_DEPENDS=	${SITE_PERL}/HTML/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/Params/CallbackRequest.pm:${PORTSDIR}/devel/p5-Params-CallbackRequest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		MasonX::Interp::WithCallbacks.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800 # inherited from devel/p5-Exception-Class
IGNORE=	requires at least Perl 5.8.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	p5-MasonX-Request-WithApacheSession
# Date created:			2003.07.21
# Whom:				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	MasonX-Request-WithApacheSession
PORTVERSION=	0.30
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MasonX
PKGNAMEPREFIX=	p5-

MAINTAINER=	nick@foobar.org
COMMENT=	An interface to Apache::Session for HTML::Mason

BUILD_DEPENDS=	${SITE_PERL}/HTML/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/Apache/Session/Wrapper.pm:${PORTSDIR}/www/p5-Apache-Session-Wrapper
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		MasonX::Request::WithApacheSession.3 \
		MasonX::Request::WithMultiSession.3

.include <bsd.port.pre.mk>

# Depends on devel/p5-Class-Container whichs needs perl 5.6.x or later
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	p5-MasonX-WebApp
# Date created:			2005.01.08
# Whom:				Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	MasonX-WebApp
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MasonX
PKGNAMEPREFIX=	p5-

MAINTAINER=	hcoyote@ghostar.org
COMMENT=	Works with HTML::Mason to do processing before Mason is invoked

RUN_DEPENDS=	${SITE_PERL}/HTML/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/Apache/Session/Wrapper.pm:${PORTSDIR}/www/p5-Apache-Session-Wrapper \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/Factory/Util.pm:${PORTSDIR}/devel/p5-Class-Factory-Util
BUILD_DEPENDS=	${RUN_DEPENDS}

.if defined(WITH_MODPERL2)
BROKEN=		Broken due the new mod_perl2 API
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif

PERL_MODBUILD=	yes

MAN3=		MasonX::WebApp.3

.include <bsd.port.pre.mk>

# Depends on devel/p5-Class-Container whichs needs perl 5.6.x or later
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>

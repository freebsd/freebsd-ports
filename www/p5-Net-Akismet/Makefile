# New ports collection makefile for:	p5-Net-Akismet
# Date created:				April 20th, 2006
# Whom:	      				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Akismet
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A Perl interface to the Akismet comment and trackback spam blocker

BUILD_DEPENDS+=	${SITE_PERL}/Bundle/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS+=	${SITE_PERL}/Bundle/LWP.pm:${PORTSDIR}/www/p5-libwww

.if !defined(WITHOUT_TEST_POD_COVERAGE)
BUILD_DEPENDS+=	${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
.endif

PERL_CONFIGURE=	yes

MAN3=		Net::Akismet.3

post-patch:
		# Grrrr, this really shouldn't be needed!
		${FIND} ${WRKSRC} -type f -name \*.orig -delete

test:		build
		@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>

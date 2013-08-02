# New ports collection makefile for:	p5-Net-Akismet
# Date created:				April 20th, 2006
# Whom:	      				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Akismet
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Perl interface to the Akismet comment and trackback spam blocker

BUILD_DEPENDS=	p5-libwww>=5.09:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-libwww>=5.09:${PORTSDIR}/www/p5-libwww

.if !defined(WITHOUT_TEST_POD_COVERAGE)
BUILD_DEPENDS+=	p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage
.endif

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::Akismet.3

test:		build
		@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>

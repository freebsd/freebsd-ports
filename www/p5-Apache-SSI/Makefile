# New ports collection makefile for:    p5-Apache-SSI
# Date created:				May 27 2001
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	Apache-SSI
PORTVERSION=	2.17
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache::SSI - Implement Server Side Includes in Perl

BUILD_DEPENDS=	${SITE_PERL}/HTML/SimpleParse.pm:${PORTSDIR}/www/p5-HTML-SimpleParse
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::SSI.3 \
		Apache::FakeSSI.3

.include <bsd.port.mk>

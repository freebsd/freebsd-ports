# New ports collection makefile for:    p5-Apache-SSI
# Date created:				May 27 2001
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	Apache-SSI
PORTVERSION=	2.19
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implement Server Side Includes in Perl

RUN_DEPENDS=	${SITE_PERL}/HTML/SimpleParse.pm:${PORTSDIR}/www/p5-HTML-SimpleParse \
		${SITE_PERL}/${PERL_ARCH}/Apache/Constants.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Apache::SSI.3 \
		Apache::FakeSSI.3

post-patch:
	${REINPLACE_CMD} -e '/STDIN/d' ${WRKSRC}/t/lib/Apache/test.pm

.include <bsd.port.mk>

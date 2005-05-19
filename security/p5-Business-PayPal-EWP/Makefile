# New ports collection makefile for:   p5-Business-PayPal-EWP
# Date created:                        Thu 12 May 2005
# Whom:                                Alfred Perlstein
#
#
# $FreeBSD$
#

PORTNAME=	Business-PayPal-EWP
PORTVERSION=	0.02
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=	p5-

MAINTAINER=	alfred@freebsd.org
COMMENT=	Perl extension to talk to paypal

USE_REINPLACE=	yes
PERL_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	${OPENSSLBASE}

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Business::PayPal::EWP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
foo:
	echo  ${PERL_LEVEL}
.endif

.if ${PERL_LEVEL} < 500600
post-patch:
	#${PERL} -pi -e 's!^our \((.*?)(?=\);)!join("","use vars qw(",split(/,/,$$1))!e' ${WRKSRC}/lib/Business/PayPal/EWP.pm
	${PERL} -pi -e 's/^our /my /' ${WRKSRC}/lib/Business/PayPal/EWP.pm
.endif

.include <bsd.port.post.mk>

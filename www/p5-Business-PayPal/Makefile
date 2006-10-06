# New ports collection makefile for:	p5-Business-PayPal
# Date created:				Fri 29 Sep 2006
# Whom:					Steven Kreuzer
#
# $FreeBSD$
#

PORTNAME=	Business-PayPal
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@f2o.org
COMMENT=	Perl extension for automating PayPal transactions

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::PayPal.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE= requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	Apache-AuthenURL
# Date created:				Sun Dec 31 20:08:48 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthenURL
PORTVERSION=	2.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Apache/mod_perl module to handle auth against external URLs

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::AuthenURL.3 Apache::AuthenURL::Cache.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Apache-DBI
# Date created:				21 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBI
PORTVERSION=	0.92
CATEGORIES=	www databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	DBI persistent connection, authentication and authorization

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Bundle/DBI.pm:${PORTSDIR}/databases/p5-DBI
.if defined(WITH_MODPERL2)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::DBI.3 Apache::AuthDBI.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	p5-Apache-DBI
# Date created:				21 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBI
PORTVERSION=	0.89
CATEGORIES=	www databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::DBI.3 Apache::AuthDBI.3

.include <bsd.port.mk>

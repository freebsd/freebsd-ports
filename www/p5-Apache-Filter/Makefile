# New ports collection makefile for:	p5-Apache-Filter
# Date created:				March 30th 2001
# Whom:	      				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-Filter
PORTVERSION=	1.019
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Apache::Filter.3 Apache::PerlRunFilter.3 \
		Apache::RegistryFilter.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>

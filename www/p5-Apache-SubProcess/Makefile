# New ports collection makefile for:	Apache-SubProcess
# Date created:				25 October 2002
# Whom:					larse@isi.edu
#
# $FreeBSD$
#

PORTNAME=	Apache-SubProcess
PORTVERSION=	0.03
CATEGORIES=	www perl
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	larse@isi.edu

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

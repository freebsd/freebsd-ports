# New ports collection makefile for:    p5-Authen-PAM
# Date created:				Mon Oct  4 1999
# Whom:	      				Matt Behrens <matt@zigg.com>
#
# $FreeBSD$
#

PORTNAME=	Authen-PAM
PORTVERSION=	0.14
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	A Perl interface to the PAM library

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	-DPAM_STRERROR_NEEDS_PAMH

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Authen::FAQ.3 \
		Authen::PAM.3

.include <bsd.port.mk>

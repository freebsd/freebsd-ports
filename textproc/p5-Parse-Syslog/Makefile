# New ports collection makefile for:	p5-Parse-Syslog
# Date created:				27 August 2001
# Whom:					Stephen Roznowski (sjr@home.com)
#
# $FreeBSD$
#

PORTNAME=	Parse-Syslog
PORTVERSION=	1.10
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 routines that present a simple interface to parse syslog files

BUILD_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy

PERL_CONFIGURE=	yes

MAN3=		Parse::Syslog.3

.include <bsd.port.mk>

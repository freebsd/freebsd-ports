# New ports collection makefile for:	p5-Parse-Syslog
# Date created:				27 August 2001
# Whom:					Stephen Roznowski (sjr@home.com)
#
# $FreeBSD$
#

PORTNAME=	Parse-Syslog
PORTVERSION=	1.09
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Parse
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl5 routines that present a simple interface to parse syslog files

BUILD_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy

PERL_CONFIGURE=	yes

MAN3=		Parse::Syslog.3

.include <bsd.port.pre.mk>

# requires Time::Local 1.07_94
.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Time/Local.pm:${PORTSDIR}/devel/p5-Time-Local
RUN_DEPENDS+=	${SITE_PERL}/Time/Local.pm:${PORTSDIR}/devel/p5-Time-Local
.endif

.include <bsd.port.mk>

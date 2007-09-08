# New ports collection makefile for:	p5-CGI-Untaint-date
# Date created:				18 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Untaint-date
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Validate a date

BUILD_DEPENDS=	${SITE_PERL}/CGI/Untaint.pm:${PORTSDIR}/www/p5-CGI-Untaint \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/${PERL_ARCH}/Date/Simple.pm:${PORTSDIR}/devel/p5-Date-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	CGI::Untaint::date.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

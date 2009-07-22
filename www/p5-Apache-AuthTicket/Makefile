# New ports collection makefile for:	Apache-AuthTicket
# Date created:				Sun Dec 31 19:57:53 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthTicket
PORTVERSION=	0.40
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules that implement a cookie-based authentication system

RUN_DEPENDS=	${SITE_PERL}/Apache/AuthCookie.pm:${PORTSDIR}/www/p5-Apache-AuthCookie \
		${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::AuthTicket.3 Apache2::AuthTicket.3

.include <bsd.port.mk>

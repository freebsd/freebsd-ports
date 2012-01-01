# New ports collection makefile for:	Apache-AuthTicket
# Date created:				Sun Dec 31 19:57:53 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthTicket
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules that implement a cookie-based authentication system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2 \
		p5-CGI.pm>=3.12:${PORTSDIR}/www/p5-CGI.pm \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-ModPerl-VersionUtil>=0:${PORTSDIR}/www/p5-ModPerl-VersionUtil \
		p5-SQL-Abstract>=0:${PORTSDIR}/databases/p5-SQL-Abstract

USE_APACHE=	20+
PERL_CONFIGURE=	yes

MAN3=		Apache::AuthTicket.3 \
		Apache::AuthTicket::Base.3 \
		Apache2::AuthTicket.3

.include <bsd.port.mk>

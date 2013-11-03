# Created by: will
# $FreeBSD$

PORTNAME=	Apache-AuthTicket
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules that implement a cookie-based authentication system

BUILD_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-CGI.pm>=3.12:${PORTSDIR}/www/p5-CGI.pm \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-ModPerl-VersionUtil>=0:${PORTSDIR}/www/p5-ModPerl-VersionUtil \
		p5-SQL-Abstract>=0:${PORTSDIR}/databases/p5-SQL-Abstract

USE_APACHE=	22+
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

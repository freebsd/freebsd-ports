# Created by: will
# $FreeBSD$

PORTNAME=	Apache-AuthTicket
PORTVERSION=	0.93
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules that implement a cookie-based authentication system

BUILD_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:www/mod_perl2
RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:www/mod_perl2 \
		p5-CGI>=3.12:www/p5-CGI \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-DBI>=0:databases/p5-DBI \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-ModPerl-VersionUtil>=0:www/p5-ModPerl-VersionUtil \
		p5-SQL-Abstract>=0:databases/p5-SQL-Abstract

USE_APACHE=	22+
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

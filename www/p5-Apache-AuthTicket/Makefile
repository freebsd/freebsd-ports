# Created by: will
# $FreeBSD$

PORTNAME=	Apache-AuthTicket
PORTVERSION=	0.94
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules that implement a cookie-based authentication system

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=1.9922:www/mod_perl2 \
		p5-Apache-AuthCookie>=3.0:www/p5-Apache-AuthCookie \
		p5-CGI>=3.12:www/p5-CGI \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-DBI>=0:databases/p5-DBI \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-ModPerl-VersionUtil>=0:www/p5-ModPerl-VersionUtil \
		p5-SQL-Abstract>=0:databases/p5-SQL-Abstract
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		apache:2.2+ perl5
USE_PERL5=	configure

# Remove README.apache-2.4.pod to avoid conflicts with p5-Apache-AuthCookie
post-patch:
	@${RM} ${WRKSRC}/README.apache-2.4.pod

.include <bsd.port.mk>

# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-Fast
PORTVERSION=	2.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEEJO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl CGI Interface for FastCGI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI>=4:www/p5-CGI \
		p5-FCGI>=0.67:www/p5-FCGI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CPAN-Changes>=0:devel/p5-CPAN-Changes \
		p5-HTML-Parser>=0:www/p5-HTML-Parser

CONFLICTS=	p5-CGI.pm-[1-3]*

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

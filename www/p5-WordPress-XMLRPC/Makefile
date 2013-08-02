# Created by: bapt <baptiste.daroussin@gmail.com>
# $FreeBSD$

PORTNAME=	WordPress-XMLRPC
PORTVERSION=	1.23
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEOCHARRE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl 5 API to WordPress XML-RPC services

BUILD_DEPENDS+=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite

USES=		perl5
USE_PERL5=	configure
MAN3=		WordPress::XMLRPC.3
PLIST_FILES=	%%SITE_PERL%%/WordPress/XMLRPC.pm \
				%%SITE_PERL%%/WordPress/XMLRPC.pod \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WordPress/XMLRPC/.packlist
PLIST_DIRS=	%%SITE_PERL%%/WordPress \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WordPress/XMLRPC \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WordPress \

.include <bsd.port.mk>

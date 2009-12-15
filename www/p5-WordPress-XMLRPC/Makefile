# New ports collection makefile for:	p5-WordPress-XMLRPC
# Date created:		2009-02-23
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	WordPress-XMLRPC
PORTVERSION=	1.22
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/L/LE/LEOCHARRE
PKGNAMEPREFIX=	p5-

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Perl 5 API to WordPress XML-RPC services

BUILD_DEPENDS+=	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite

PERL_CONFIGURE=	yes
MAN3=		WordPress::XMLRPC.3
PLIST_FILES=	%%SITE_PERL%%/WordPress/XMLRPC.pm \
				%%SITE_PERL%%/WordPress/XMLRPC.pod \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WordPress/XMLRPC/.packlist
PLIST_DIRS=	%%SITE_PERL%%/WordPress \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WordPress/XMLRPC \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WordPress \

.include <bsd.port.mk>

# New ports collection makefile for:    CGI::Builder::TT2
# Date created:                         20 Oct 2004
# Whom:                                 Daniel Wijnands <daniel@itxl.nl>
#
# $FreeBSD$
#

PORTNAME=	CGI-Builder-TT2
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/L/LA/LARSEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	daniel@itxl.nl
COMMENT=	CGI::Builder and Template Toolkit 2 integration

BUILD_DEPENDS=	${SITE_PERL}/CGI/Builder.pm:${PORTSDIR}/www/p5-CGI-Builder \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::Builder::TT2.3

.include <bsd.port.mk>

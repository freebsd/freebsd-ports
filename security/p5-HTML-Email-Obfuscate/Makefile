# New ports collection makefile for:	p5-HTML-Email-Obfuscate
# Date created:				2007/02/14
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	HTML-Email-Obfuscate
PORTVERSION=	1.00
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Obfuscates HTML email addresses that look normal

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::Email::Obfuscate.3

.include <bsd.port.mk>

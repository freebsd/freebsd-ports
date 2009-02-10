# New ports collection makefile for:	p5-HTML-StripScripts-Parser
# Date Created:				May 08, 2008
# Whom:					kftseng@iyard.org
#
# $FreeBSD$
#

PORTNAME=	HTML-StripScripts-Parser
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSS filter using HTML::Parser

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTML/StripScripts.pm:${PORTSDIR}/www/p5-HTML-StripScripts

PERL_CONFIGURE=	yes

MAN3=		HTML::StripScripts::Parser.3

.include <bsd.port.mk>

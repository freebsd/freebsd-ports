# New ports collection makefile for:	p5-HTML-StripScripts-Parser
# Date Created:				May 08, 2008
# Whom:					kftseng@iyard.org
#
# $FreeBSD$
#

PORTNAME=	HTML-StripScripts-Parser
PORTVERSION=	1.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSS filter using HTML::Parser

RUN_DEPENDS=	p5-HTML-Parser>=3.56:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-StripScripts>=1.05:${PORTSDIR}/www/p5-HTML-StripScripts
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::StripScripts::Parser.3

.include <bsd.port.mk>

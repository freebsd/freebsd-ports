# New ports collection makefile for:	HTML-Mason
# Date created:				31 May 2000
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	HTML-Mason
PORTVERSION=	1.01.5
DISTNAME=	${PORTNAME}-1.015
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	dsh@vlink.ru

RUN_DEPENDS=	${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM \
		${SITE_PERL}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate

IS_INTERACTIVE=	yes
PERL_CONFIGURE=	yes
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Bundle::HTML::Mason.3 HTML::Mason.3 HTML::Mason::Admin.3 \
		HTML::Mason::ApacheHandler.3 HTML::Mason::Commands.3 \
		HTML::Mason::Component.3 HTML::Mason::Components.3 \
		HTML::Mason::Devel.3 HTML::Mason::Interp.3 \
		HTML::Mason::MethodMaker.3 HTML::Mason::Parser.3 \
		HTML::Mason::Request.3 HTML::Mason::Tests.3

.include <bsd.port.mk>

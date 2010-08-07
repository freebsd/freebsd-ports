# New ports collection makefile for:	Tenjin
# Date created:		04 Dec 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tenjin
PORTVERSION=	0.062
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast templating engine with support for embedded

RUN_DEPENDS=	p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser

PERL_CONFIGURE=	yes

MAN3=	Tenjin.3 \
	Tenjin::Context.3 \
	Tenjin::Preprocessor.3 \
	Tenjin::Template.3 \
	Tenjin::Util.3

.include <bsd.port.mk>

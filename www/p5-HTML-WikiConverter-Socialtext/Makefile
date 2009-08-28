# New ports collection makefile for:	p5-HTML-WikiConverter-Socialtext
# Date created:				2006/09/08
# Whom:	      				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-WikiConverter-Socialtext
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert HTML to Socialtext markup

BUILD_DEPENDS=	p5-HTML-WikiConverter>=0.60:${PORTSDIR}/www/p5-HTML-WikiConverter \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		HTML::WikiConverter::Socialtext.3

.include <bsd.port.mk>

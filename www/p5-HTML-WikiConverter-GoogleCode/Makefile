# New ports collection makefile for:	p5-HTML-WikiConverter-GoogleCode
# Date created:				2008/05/18
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	HTML-WikiConverter-GoogleCode
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert HTML to Google Code wiki markup

BUILD_DEPENDS=	p5-HTML-WikiConverter>=0.60:${PORTSDIR}/www/p5-HTML-WikiConverter \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		HTML::WikiConverter::GoogleCode.3

.include <bsd.port.mk>

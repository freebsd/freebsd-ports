# New ports collection makefile for:	p5-HTML-WikiConverter-WakkaWiki
# Date created:				2006/06/27
# Whom:	      				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-WikiConverter-WakkaWiki
PORTVERSION=	0.50
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert HTML to WakkaWiki markup

BUILD_DEPENDS=	p5-HTML-WikiConverter>=0.54:${PORTSDIR}/www/p5-HTML-WikiConverter \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		HTML::WikiConverter::WakkaWiki.3

.include <bsd.port.mk>

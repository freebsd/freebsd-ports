# New ports collection makefile for:	www/p5-CGI-Prototype
# Date created:				20 April 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Prototype
PORTVERSION=	0.9054
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Create a CGI application by subclassing

COMMON_DEPENDS=	p5-Class-Prototyped>0:${PORTSDIR}/devel/p5-Class-Prototyped \
		p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	CGI::Prototype.3 \
	CGI::Prototype::Hidden.3

.include <bsd.port.mk>

# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-SSI
PORTVERSION=	0.92
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use SSI from CGI scripts

RUN_DEPENDS=	p5-HTML-SimpleParse>=0:www/p5-HTML-SimpleParse \
		p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-TimeDate>=0:devel/p5-TimeDate
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

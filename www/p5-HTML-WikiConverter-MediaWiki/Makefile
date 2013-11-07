# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	HTML-WikiConverter-MediaWiki
PORTVERSION=	0.59
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert HTML to MediaWiki markup

BUILD_DEPENDS=	p5-HTML-WikiConverter>=0.63:${PORTSDIR}/www/p5-HTML-WikiConverter \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

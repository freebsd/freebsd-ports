# $FreeBSD$

PORTNAME=	HTML-RewriteAttributes
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple yet powerful HTML attribute rewriting

BUILD_DEPENDS=	p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Tagset>0:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-URI>0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

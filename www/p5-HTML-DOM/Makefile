# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-DOM
PORTVERSION=	0.054
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Implementation of the HTML Document Object Model

BUILD_DEPENDS=	p5-CSS-DOM>=0:${PORTSDIR}/www/p5-CSS-DOM \
		p5-HTML-Element-Library>=0:${PORTSDIR}/www/p5-HTML-Element-Library \
		p5-HTML-Encoding>=0:${PORTSDIR}/www/p5-HTML-Encoding \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-Hash-Util-FieldHash-Compat>=0:${PORTSDIR}/devel/p5-Hash-Util-FieldHash-Compat \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-constant-lexical>0:${PORTSDIR}/devel/p5-constant-lexical
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

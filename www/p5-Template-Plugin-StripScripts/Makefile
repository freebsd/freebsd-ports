# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Template-Plugin-StripScripts
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	TT plugin to filter HTML against XSS

LICENSE=	MIT

BUILD_DEPENDS=	p5-HTML-StripScripts-Parser>=0.99:www/p5-HTML-StripScripts-Parser \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>

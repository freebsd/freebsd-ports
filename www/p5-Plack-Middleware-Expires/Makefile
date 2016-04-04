# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Plack-Middleware-Expires
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module mod_expires for Plack

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Date>=0:www/p5-HTTP-Date \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Plack>=0.9937:www/p5-Plack \
		p5-Try-Tiny>=0.06:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>

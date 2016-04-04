# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Server
PORTVERSION=	0.28
PORTREVISION=	4
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Catalyst Server Plugin: Base & XMLRPC

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.90:www/p5-Catalyst-Runtime \
		p5-Catalyst-DispatchType-Regex>=5.90000:www/p5-Catalyst-DispatchType-Regex \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Clone-Fast>=0:devel/p5-Clone-Fast \
		p5-RPC-XML>=0:net/p5-RPC-XML
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pagerduty
PORTVERSION=	2.1.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight interface for calling the PagerDuty Integration API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-json>=1.7.7:devel/rubygem-json

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	script/setup.sh

.include <bsd.port.mk>

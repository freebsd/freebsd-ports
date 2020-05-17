# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sassc
PORTVERSION=	2.2.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	22

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use libsass with Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ffi>=1.9<2:devel/rubygem-ffi

USES=		gem gmake
USE_RUBY=	yes

# Workaround for https://gitlab.com/gitlab-org/gitlab/-/issues/216740
PORTSCOUT=	limit:^2\.2\.

.include <bsd.port.mk>

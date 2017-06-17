# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	airbrussh
PORTVERSION=	1.3.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement log formatter for SSHKit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-sshkit>=1.7.1:security/rubygem-sshkit

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

SHEBANG_FILES=	bin/setup

.include <bsd.port.mk>

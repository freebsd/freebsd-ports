PORTNAME=	airbrussh
PORTVERSION=	1.5.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement log formatter for SSHKit
WWW=		https://github.com/mattbrictson/airbrussh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-sshkit>=1.7.1:security/rubygem-sshkit

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/setup

.include <bsd.port.mk>

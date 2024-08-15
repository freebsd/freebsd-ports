PORTNAME=	capistrano
PORTVERSION=	3.19.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Utility for executing commands in parallel on multiple machines
WWW=		https://github.com/capistrano/capistrano

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-airbrussh>=1.0.0:security/rubygem-airbrussh \
		rubygem-i18n>=0:devel/rubygem-i18n \
		rubygem-rake>=10.0.0:devel/rubygem-rake \
		rubygem-sshkit>=1.9.0:security/rubygem-sshkit

USES=		gem shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/cap bin/capify

SHEBANG_FILES=	.docker/ubuntu_setup.sh

.include <bsd.port.mk>

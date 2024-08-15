PORTNAME=	sshkit
PORTVERSION=	1.23.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for remotely running commands on groups of servers
WWW=		https://github.com/capistrano/sshkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-net-scp>=1.1.2:security/rubygem-net-scp \
		rubygem-net-sftp>=2.1.2:security/rubygem-net-sftp \
		rubygem-net-ssh>=2.8.0,2:security/rubygem-net-ssh

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	.docker/ubuntu_setup.sh

.include <bsd.port.mk>

PORTNAME=	sshkit
PORTVERSION=	1.21.6
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for remotely running commands on groups of servers
WWW=		https://github.com/capistrano/sshkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-net-scp>=1.1.2:security/rubygem-net-scp \
		rubygem-net-ssh>=2.8.0,2:security/rubygem-net-ssh

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

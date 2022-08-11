PORTNAME=	net-sftp
PORTVERSION=	2.1.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the SFTP client protocol

LICENSE=	MIT

RUN_DEPENDS=	rubygem-net-ssh>=2.6.5:security/rubygem-net-ssh

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>

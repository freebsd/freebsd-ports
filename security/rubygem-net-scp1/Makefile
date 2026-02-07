PORTNAME=	net-scp
PORTVERSION=	1.2.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Non-interactive SCP processing
WWW=		https://github.com/net-ssh/net-scp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-net-ssh>=2.6.5,2:security/rubygem-net-ssh

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>

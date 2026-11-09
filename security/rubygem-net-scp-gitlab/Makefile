PORTNAME=	net-scp
PORTVERSION=	4.2.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Non-interactive SCP processing
WWW=		https://github.com/net-ssh/net-scp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-net-ssh-gitlab>=2.6.5<9.0.0:security/rubygem-net-ssh-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

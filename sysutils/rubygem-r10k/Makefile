# $FreeBSD$

PORTNAME=	r10k
PORTVERSION=	2.6.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool for deploying Puppet environments and modules

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-colored>=1.2:textproc/rubygem-colored \
		rubygem-cri>=2.6.1:devel/rubygem-cri \
		rubygem-gettext-setup>=0.5:devel/rubygem-gettext-setup \
		rubygem-log4r>=1.1.10:sysutils/rubygem-log4r \
		rubygem-multi_json>=1.10:devel/rubygem-multi_json \
		rubygem-puppet_forge>=2.2.8:sysutils/rubygem-puppet_forge

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

PLIST_FILES=	bin/r10k

SHEBANG_FILES=	integration/*/*.sh

.include <bsd.port.mk>

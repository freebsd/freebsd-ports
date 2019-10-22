# $FreeBSD$

PORTNAME=	r10k
PORTVERSION=	3.3.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Tool for deploying Puppet environments and modules

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-colored>=1.2:textproc/rubygem-colored \
		rubygem-cri>=2.6.1:devel/rubygem-cri \
		rubygem-gettext-setup>=0.5:devel/rubygem-gettext-setup \
		rubygem-log4r>=1.1.10:sysutils/rubygem-log4r \
		rubygem-multi_json>=1.10:devel/rubygem-multi_json \
		rubygem-puppet_forge>=2.2.8:sysutils/rubygem-puppet_forge

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/r10k

SHEBANG_FILES=	integration/*/*.sh

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/lib/r10k/settings.rb \
		${WRKSRC}/lib/r10k/settings/loader.rb

.include <bsd.port.mk>

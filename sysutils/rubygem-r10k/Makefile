PORTNAME=	r10k
PORTVERSION=	5.0.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Tool for deploying Puppet environments and modules
WWW=		https://github.com/puppetlabs/r10k

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-colored2>=3.1.2:textproc/rubygem-colored2 \
		rubygem-cri>=2.15.10:devel/rubygem-cri \
		rubygem-gettext-setup>=1.0:devel/rubygem-gettext-setup \
		rubygem-jwt>=2.2.3:www/rubygem-jwt \
		rubygem-log4r>=1.1.10:sysutils/rubygem-log4r \
		rubygem-multi_json>=1.10:devel/rubygem-multi_json \
		rubygem-puppet_forge>=4.1:sysutils/rubygem-puppet_forge

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/r10k

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/lib/r10k/settings.rb \
		${WRKSRC}/lib/r10k/settings/loader.rb

.include <bsd.port.mk>

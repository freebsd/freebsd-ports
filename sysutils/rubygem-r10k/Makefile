PORTNAME=	r10k
PORTVERSION=	5.0.2
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Tool for deploying Puppet environments and modules
WWW=		https://github.com/puppetlabs/r10k

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-colored2>=3.0<5.0:textproc/rubygem-colored2 \
		rubygem-cri>=2.15.10:devel/rubygem-cri \
		rubygem-gettext-setup>=0.24<2.0:devel/rubygem-gettext-setup \
		rubygem-jwt2>=2.2.3<3:www/rubygem-jwt2 \
		rubygem-log4r>=1.1.10<1.1.10_99:sysutils/rubygem-log4r \
		rubygem-minitar>=0.9<2:archivers/rubygem-minitar \
		rubygem-multi_json>=1.10<2:devel/rubygem-multi_json \
		rubygem-puppet_forge>=4.1.0<7:sysutils/rubygem-puppet_forge

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/r10k

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/lib/r10k/settings.rb \
		${WRKSRC}/lib/r10k/settings/loader.rb

.include <bsd.port.mk>

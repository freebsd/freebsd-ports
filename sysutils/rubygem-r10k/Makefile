# $FreeBSD$

PORTNAME=	r10k
PORTVERSION=	2.0.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool for deploying Puppet environments and modules

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-colored>=1.2:${PORTSDIR}/textproc/rubygem-colored \
		rubygem-cri>=2.6.1:${PORTSDIR}/devel/rubygem-cri \
		rubygem-faraday>=0.9.0:${PORTSDIR}/www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9.0:${PORTSDIR}/www/rubygem-faraday_middleware \
		rubygem-faraday_middleware-multi_json>=0.0.6:${PORTSDIR}/devel/rubygem-faraday_middleware-multi_json \
		rubygem-log4r>=1.1.10:${PORTSDIR}/sysutils/rubygem-log4r \
		rubygem-minitar>=0:${PORTSDIR}/archivers/rubygem-minitar \
		rubygem-multi_json>=1.10:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-semantic_puppet>=0.1.0:${PORTSDIR}/devel/rubygem-semantic_puppet

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/r10k

.include <bsd.port.mk>

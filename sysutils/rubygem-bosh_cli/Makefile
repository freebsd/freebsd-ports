# $FreeBSD$

PORTNAME=	bosh_cli
PORTVERSION=	1.3262.26.0
PORTREVISION=	3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	BOSH CLI

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-blobstore_client>=1.3262.24.0:devel/rubygem-blobstore_client \
		rubygem-bosh_common>=1.3262.24.0:devel/rubygem-bosh_common \
		rubygem-bosh-template>=1.3262.24.0:devel/rubygem-bosh-template \
		rubygem-cf-uaa-lib>=3.2.1:devel/rubygem-cf-uaa-lib \
		rubygem-highline>=1.6.2:devel/rubygem-highline \
		rubygem-httpclient>=2.4.0:www/rubygem-httpclient \
		rubygem-json_pure>=1.7:devel/rubygem-json_pure \
		rubygem-minitar>=0.5.4:archivers/rubygem-minitar \
		rubygem-netaddr>=1.5.0:devel/rubygem-netaddr \
		rubygem-net-scp>=1.1.0:security/rubygem-net-scp \
		rubygem-net-ssh>=2.9.2:security/rubygem-net-ssh \
		rubygem-net-ssh-gateway1>=1.2.0:security/rubygem-net-ssh-gateway1 \
		rubygem-progressbar09>=0.9.0:devel/rubygem-progressbar09 \
		rubygem-sshkey>=1.7.0:security/rubygem-sshkey \
		rubygem-terminal-table>=1.4.3:textproc/rubygem-terminal-table

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/bosh

post-install:
	${INSTALL_SCRIPT} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/bin/bosh ${STAGEDIR}${PREFIX}/bin
	${REINPLACE_CMD} -i '' \
		-e "s|require_relative '../bin/optionally_run_with_bundler'|require_relative '../${GEM_LIB_DIR}/bin/optionally_run_with_bundler'|" \
		'${STAGEDIR}${PREFIX}/bin/bosh'

.include <bsd.port.mk>

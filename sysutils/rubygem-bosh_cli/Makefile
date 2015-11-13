# $FreeBSD$

PORTNAME=	bosh_cli
PORTVERSION=	1.3098.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	BOSH CLI

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-blobstore_client>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-blobstore_client \
		rubygem-bosh_common>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-bosh_common \
		rubygem-bosh-template>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-bosh-template \
		rubygem-cf-uaa-lib>=3.2.1:${PORTSDIR}/devel/rubygem-cf-uaa-lib \
		rubygem-highline>=1.6.2:${PORTSDIR}/devel/rubygem-highline \
		rubygem-httpclient>=2.4.0:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-json_pure>=1.7:${PORTSDIR}/devel/rubygem-json_pure \
		rubygem-minitar>=0.5.4:${PORTSDIR}/archivers/rubygem-minitar \
		rubygem-netaddr>=1.5.0:${PORTSDIR}/devel/rubygem-netaddr \
		rubygem-net-scp>=1.1.0:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-net-ssh>=2.2.1:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-net-ssh-gateway>=1.2.0:${PORTSDIR}/security/rubygem-net-ssh-gateway \
		rubygem-progressbar>=0.9.0:${PORTSDIR}/devel/rubygem-progressbar \
		rubygem-sshkey>=1.7.0:${PORTSDIR}/security/rubygem-sshkey \
		rubygem-terminal-table>=1.4.3:${PORTSDIR}/textproc/rubygem-terminal-table

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/bosh

post-install:
	${INSTALL_SCRIPT} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/bin/bosh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

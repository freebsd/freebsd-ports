PORTNAME=	bolt
PORTVERSION=	3.30.0
PORTREVISION=	5
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Execute commands remotely over SSH and WinRM
WWW=		https://github.com/puppetlabs/bolt

LICENSE=	APACHE20

RUN_DEPENDS=	r10k:sysutils/rubygem-r10k \
		rubygem-addressable>=2.5:www/rubygem-addressable \
		rubygem-aws-sdk-ec2>1:devel/rubygem-aws-sdk-ec2 \
		rubygem-CFPropertyList>=2.2:devel/rubygem-CFPropertyList \
		rubygem-concurrent-ruby11>=1.0:devel/rubygem-concurrent-ruby11 \
		rubygem-ffi>=1.13<2:devel/rubygem-ffi \
		rubygem-hiera-eyaml>=3:sysutils/rubygem-hiera-eyaml \
		rubygem-jwt>=2.2:www/rubygem-jwt \
		rubygem-logging>=2.2:devel/rubygem-logging \
		rubygem-minitar>=0.6:archivers/rubygem-minitar \
		rubygem-net-scp>=1.2<5:security/rubygem-net-scp \
		rubygem-net-ssh6>=4.0<8:security/rubygem-net-ssh6 \
		rubygem-net-ssh-krb>=0.5:security/rubygem-net-ssh-krb \
		rubygem-orchestrator_client>=0.5:net/rubygem-orchestrator_client \
		rubygem-puppet-resource_api>=1.8.1:devel/rubygem-puppet-resource_api \
		rubygem-puppet-strings>=2.3.0:textproc/rubygem-puppet-strings \
		rubygem-puppetfile-resolver>=0.6.2:sysutils/rubygem-puppetfile-resolver \
		rubygem-ruby_smb>=1.0:net/rubygem-ruby_smb \
		rubygem-terminal-table3>=3.0<4:textproc/rubygem-terminal-table3 \
		rubygem-winrm-fs>=1.3:filesystems/rubygem-winrm-fs \
		rubygem-winrm>=2.0:sysutils/rubygem-winrm

USES=		gem shebangfix

CONFLICTS_INSTALL=rubygem-openbolt
ruby_OLD_CMD+=	/opt/puppetlabs/puppet/bin/ruby
SHEBANG_FILES=	libexec/*

NO_ARCH=	yes

PLIST_FILES=	bin/bolt \
		etc/bash_completion.d/bolt

OPTIONS_SINGLE=	PUPPET
OPTIONS_SINGLE_PUPPET=PUPPET7 PUPPET8
OPTIONS_DEFAULT=PUPPET8

PUPPET7_DESC=	Depend on sysutils/puppet7
PUPPET8_DESC=	Depend on sysutils/puppet8

PUPPET7_RUN_DEPENDS=puppet:sysutils/puppet7
PUPPET8_RUN_DEPENDS=puppet:sysutils/puppet8

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/resources/bolt_bash_completion.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/bolt

.include <bsd.port.mk>

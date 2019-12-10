# $FreeBSD$

PORTNAME=	bolt
PORTVERSION=	1.42.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Execute commands remotely over SSH and WinRM

LICENSE=	APACHE20

RUN_DEPENDS=	puppet:sysutils/puppet6 \
		r10k:sysutils/rubygem-r10k \
		rubygem-addressable>=2.5:www/rubygem-addressable \
		rubygem-CFPropertyList>=2.2:devel/rubygem-CFPropertyList \
		rubygem-aws-sdk-ec2>0:devel/rubygem-aws-sdk-ec2 \
		rubygem-concurrent-ruby>=1.0:devel/rubygem-concurrent-ruby \
		rubygem-docker-api>=1.34:net/rubygem-docker-api \
		rubygem-hiera-eyaml>=3:sysutils/rubygem-hiera-eyaml \
		rubygem-logging>=2.2:devel/rubygem-logging \
		rubygem-net-scp>=1.2:security/rubygem-net-scp \
		rubygem-net-ssh>=4.0:security/rubygem-net-ssh \
		rubygem-orchestrator_client>=0.3:net/rubygem-orchestrator_client \
		rubygem-puppet-resource_api>=0:devel/rubygem-puppet-resource_api \
		rubygem-puppet-strings>=0:textproc/rubygem-puppet-strings \
		rubygem-ruby_smb>=0:net/rubygem-ruby_smb \
		rubygem-terminal-table>=1.8:textproc/rubygem-terminal-table \
		rubygem-winrm-fs>=1.3:sysutils/rubygem-winrm-fs \
		rubygem-winrm>=2.0:sysutils/rubygem-winrm

USES=		gem shebangfix
USE_RUBY=	yes

ruby_OLD_CMD+=	/opt/puppetlabs/puppet/bin/ruby
SHEBANG_FILES=	libexec/*

PLIST_FILES=	bin/bolt \
		bin/bolt-inventory-pdb

.include <bsd.port.mk>

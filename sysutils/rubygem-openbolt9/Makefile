PORTNAME=	openbolt
PORTVERSION=	9.1.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	9

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Execute commands remotely over SSH and WinRM
WWW=		https://github.com/OpenVoxProject/openbolt/

LICENSE=	APACHE20

RUN_DEPENDS=	puppet:sysutils/openvox-agent9 \
		r10k:sysutils/rubygem-r10k \
		rubygem-addressable>=2.5:www/rubygem-addressable \
		rubygem-aws-sdk-ec2>1:devel/rubygem-aws-sdk-ec2 \
		rubygem-bindata24<3:devel/rubygem-bindata24 \
		rubygem-CFPropertyList>=2.2:devel/rubygem-CFPropertyList \
		rubygem-choria-mcorpc-support>=2.28:sysutils/rubygem-choria-mcorpc-support \
		rubygem-concurrent-ruby11>=1.0:devel/rubygem-concurrent-ruby11 \
		rubygem-ffi>=1.13<2:devel/rubygem-ffi \
		rubygem-hiera-eyaml>=3<6:sysutils/rubygem-hiera-eyaml \
		rubygem-json2>=2.6<3:devel/rubygem-json2 \
		rubygem-jwt>=2.2<4:www/rubygem-jwt \
		rubygem-logging>=2.2:devel/rubygem-logging \
		rubygem-minitar>=0.6<2.0:archivers/rubygem-minitar \
		rubygem-net-scp>=1.2<5:security/rubygem-net-scp \
		rubygem-net-ssh6>=4.0<8:security/rubygem-net-ssh6 \
		rubygem-net-ssh-krb>=0.5<1:security/rubygem-net-ssh-krb \
		rubygem-openvox-strings>=5.0<8:textproc/rubygem-openvox-strings \
		rubygem-puppet-resource_api>=1.8.1:devel/rubygem-puppet-resource_api \
		rubygem-puppetfile-resolver>=0.6.2<1:sysutils/rubygem-puppetfile-resolver \
		rubygem-ruby_smb>=1.0:net/rubygem-ruby_smb \
		rubygem-terminal-table>=4.0<5:textproc/rubygem-terminal-table \
		rubygem-winrm-fs>=1.3<2:filesystems/rubygem-winrm-fs \
		rubygem-winrm>=2.0<3:sysutils/rubygem-winrm

USES=		gem shebangfix

CONFLICTS_INSTALL=	rubygem-bolt
ruby_OLD_CMD+=	/opt/puppetlabs/puppet/bin/ruby
SHEBANG_FILES=	libexec/*

NO_ARCH=	yes

PLIST_FILES=	bin/bolt \
		etc/bash_completion.d/bolt

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/resources/bolt_bash_completion.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/bolt

.include <bsd.port.mk>

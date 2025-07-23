PORTNAME=	chef
PORTVERSION=	18.7.10
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Systems integration framework. Client part
WWW=		https://www.chef.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-aws-sdk-s3>=1.91<2:devel/rubygem-aws-sdk-s3 \
		rubygem-aws-sdk-secretsmanager>=1.46<2:devel/rubygem-aws-sdk-secretsmanager \
		rubygem-chef-config>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef-config \
		rubygem-chef-utils>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef-utils \
		rubygem-chef-vault>=0:sysutils/rubygem-chef-vault \
		rubygem-chef-zero>=15.0.17:sysutils/rubygem-chef-zero \
		rubygem-corefoundation>=0.3.4<0.4:devel/rubygem-corefoundation \
		rubygem-diff-lcs>=1.2.4:textproc/rubygem-diff-lcs \
		rubygem-erubis>=2.7<3:www/rubygem-erubis \
		rubygem-ffi>=1.15.5:devel/rubygem-ffi \
		rubygem-ffi-libarchive>=1.0.3<2:devel/rubygem-ffi-libarchive \
		rubygem-ffi-yajl>=2.2<3:devel/rubygem-ffi-yajl \
		rubygem-iniparse>=1.4<2:devel/rubygem-iniparse \
		rubygem-inspec-core>=5<6:devel/rubygem-inspec-core \
		rubygem-license-acceptance>=1.0.5<3:sysutils/rubygem-license-acceptance \
		rubygem-mixlib-archive>=0.4<2.0:devel/rubygem-mixlib-archive \
		rubygem-mixlib-authentication>=2.1<4:devel/rubygem-mixlib-authentication \
		rubygem-mixlib-cli>=2.1.1<3.0:devel/rubygem-mixlib-cli \
		rubygem-mixlib-log>=2.0.3<3.2:devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=3.1.1<4.0:devel/rubygem-mixlib-shellout \
		rubygem-net-ftp>=0:ftp/rubygem-net-ftp \
		rubygem-net-sftp>=2.1.2<5.0:security/rubygem-net-sftp \
		rubygem-ohai>=18.0<19:sysutils/rubygem-ohai \
		rubygem-plist>=3.2<4:devel/rubygem-plist \
		rubygem-proxifier2>=1.1<2:net/rubygem-proxifier2 \
		rubygem-syslog-logger>=1.6<2:sysutils/rubygem-syslog-logger \
		rubygem-train-core>=3.10:net/rubygem-train-core \
		rubygem-train-rest>=0.4.1:net/rubygem-train-rest \
		rubygem-train-winrm>=0.2.17:net/rubygem-train-winrm \
		rubygem-unf_ext>=0.0.8.2:textproc/rubygem-unf_ext \
		rubygem-uuidtools>=2.1.5:devel/rubygem-uuidtools \
		rubygem-vault>=0.18.2<0.19:security/rubygem-vault

USES=		cpe gem shebangfix

NO_ARCH=	yes

SUB_LIST=	RUBY=${RUBY}
USE_RC_SUBR=	chef_client

SHEBANG_FILES=	spec/functional/assets/chefinittest \
		spec/functional/assets/testchefsubsys

post-install:
	${MKDIR} ${STAGEDIR}/var/chef

.include <bsd.port.mk>

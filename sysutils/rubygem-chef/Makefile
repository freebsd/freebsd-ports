# Created by: Renaud Chaput <renchap@cocoa-x.com>

PORTNAME=	chef
PORTVERSION=	16.13.16
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Systems integration framework. Client part

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-bcrypt_pbkdf>=1.1<2:security/rubygem-bcrypt_pbkdf \
		rubygem-bundler>=1.10:sysutils/rubygem-bundler \
		rubygem-chef-config>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef-config \
		rubygem-chef-utils>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef-utils \
		rubygem-chef-vault>=0:sysutils/rubygem-chef-vault \
		rubygem-chef-zero>=14.0.11:sysutils/rubygem-chef-zero \
		rubygem-diff-lcs>=1.2.4:textproc/rubygem-diff-lcs \
		rubygem-ed25519>=1.2<2:security/rubygem-ed25519 \
		rubygem-erubis>=2.7<3:www/rubygem-erubis \
		rubygem-ffi>=1.9.25:devel/rubygem-ffi \
		rubygem-ffi-libarchive>=1.0.3<2:devel/rubygem-ffi-libarchive \
		rubygem-ffi-yajl>=2.2<3:devel/rubygem-ffi-yajl \
		rubygem-highline>=1.6.9<3:devel/rubygem-highline \
		rubygem-iniparse>=1.4<2:devel/rubygem-iniparse \
		rubygem-inspec-core>=4.23<5:devel/rubygem-inspec-core \
		rubygem-license-acceptance>=1.0.5<3:sysutils/rubygem-license-acceptance \
		rubygem-mixlib-archive>=0.4<2:devel/rubygem-mixlib-archive \
		rubygem-mixlib-authentication>=2.1<4:devel/rubygem-mixlib-authentication \
		rubygem-mixlib-cli>=2.1.1<3:devel/rubygem-mixlib-cli \
		rubygem-mixlib-log>=2.0.3<4:devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=3.1.1<4:devel/rubygem-mixlib-shellout \
		rubygem-net-sftp>=2.1.2<4:security/rubygem-net-sftp \
		rubygem-net-ssh5>=5.1,2<7,2:security/rubygem-net-ssh5 \
		rubygem-net-ssh-multi>=1.2.1<2:security/rubygem-net-ssh-multi \
		rubygem-ohai>=16.0<17:sysutils/rubygem-ohai \
		rubygem-plist>=3.2<4:devel/rubygem-plist \
		rubygem-proxifier>=1.0<2:net/rubygem-proxifier \
		rubygem-syslog-logger>=1.6<2:sysutils/rubygem-syslog-logger \
		rubygem-train-core>=3.2.28<4:net/rubygem-train-core \
		rubygem-train-winrm>=0.2.5:net/rubygem-train-winrm \
		rubygem-tty-prompt>=0.21<1:devel/rubygem-tty-prompt \
		rubygem-tty-screen>=0.6<1:devel/rubygem-tty-screen \
		rubygem-tty-table>=0.11<1:devel/rubygem-tty-table \
		rubygem-uuidtools>=2.1.5<2.2:devel/rubygem-uuidtools

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SUB_LIST=	RUBY=${RUBY}
USE_RC_SUBR=	chef_client

SHEBANG_FILES=	spec/functional/assets/chefinittest \
		spec/functional/assets/testchefsubsys
SHEBANG_LANG=	ksh

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/spec/data/apt/chef-integration-test*/debian/rules

post-install:
#	${INSTALL_MAN} ${WRKSRC}/distro/common/man/man1/*.1 ${STAGEDIR}${MANPREFIX}/man/man1/
#	${INSTALL_MAN} ${WRKSRC}/distro/common/man/man8/*.8 ${STAGEDIR}${MANPREFIX}/man/man8/
	${MKDIR} ${STAGEDIR}/var/chef

.include <bsd.port.mk>

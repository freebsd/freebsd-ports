# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	chef
PORTVERSION=	15.14.0
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Systems integration framework. Client part

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-bcrypt_pbkdf>=1.0.1<2:security/rubygem-bcrypt_pbkdf \
		rubygem-bundler>=1.10:sysutils/rubygem-bundler \
		rubygem-chef-config>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef-config \
		rubygem-chef-utils15>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef-utils15 \
		rubygem-chef-zero>=14.0.11:sysutils/rubygem-chef-zero \
		rubygem-diff-lcs>=1.2.4<2:textproc/rubygem-diff-lcs \
		rubygem-ed25519>=1.2<2:security/rubygem-ed25519 \
		rubygem-erubis>=2.7<3:www/rubygem-erubis \
		rubygem-ffi>=1.9.25:devel/rubygem-ffi \
		rubygem-ffi-libarchive>=1.0.3<2:devel/rubygem-ffi-libarchive \
		rubygem-ffi-yajl>=2.2<3:devel/rubygem-ffi-yajl \
		rubygem-highline1>=1.6.9<2:devel/rubygem-highline1 \
		rubygem-iniparse>=1.4<2:devel/rubygem-iniparse \
		rubygem-license-acceptance>=1.0.5:sysutils/rubygem-license-acceptance \
		rubygem-mixlib-archive>=0.4<2:devel/rubygem-mixlib-archive \
		rubygem-mixlib-authentication>=2.1<4:devel/rubygem-mixlib-authentication \
		rubygem-mixlib-cli>=2.1.1<3:devel/rubygem-mixlib-cli \
		rubygem-mixlib-log>=2.0.3<4:devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=3.0.3<4:devel/rubygem-mixlib-shellout \
		rubygem-net-sftp>=2.1.2<4:security/rubygem-net-sftp \
		rubygem-net-ssh>=4.2,2<7,2:security/rubygem-net-ssh \
		rubygem-net-ssh-multi>=1.2.1<2:security/rubygem-net-ssh-multi \
		rubygem-ohai>=15.0<16:sysutils/rubygem-ohai \
		rubygem-plist>=3.2<4:devel/rubygem-plist \
		rubygem-proxifier>=1.0<2:net/rubygem-proxifier \
		rubygem-syslog-logger>=1.6<2:sysutils/rubygem-syslog-logger \
		rubygem-train-core>=3.2.28<4:net/rubygem-train-core \
		rubygem-train-winrm>=0.2.5:net/rubygem-train-winrm \
		rubygem-tty-screen>=0.6<1:devel/rubygem-tty-screen \
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

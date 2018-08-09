# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	chef
PORTVERSION=	12.22.5
CATEGORIES=	sysutils
MASTER_SITES=	RG
PKGNAMESUFFIX=	12

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Systems integration framework. Client part

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-bundler>=1.10:sysutils/rubygem-bundler \
		rubygem-chef-config12=${PORTVERSION}:sysutils/rubygem-chef-config12 \
		rubygem-chef-zero5<13.0:sysutils/rubygem-chef-zero5 \
		rubygem-diff-lcs>=1.2.4:textproc/rubygem-diff-lcs \
		rubygem-erubis>=2.7:www/rubygem-erubis \
		rubygem-ffi-yajl>=2.2:devel/rubygem-ffi-yajl \
		rubygem-highline>=1.6.9:devel/rubygem-highline \
		rubygem-iniparse>=1.4:devel/rubygem-iniparse \
		rubygem-mixlib-archive>=0.4:devel/rubygem-mixlib-archive \
		rubygem-mixlib-authentication>=1.4:devel/rubygem-mixlib-authentication \
		rubygem-mixlib-cli>=1.7:devel/rubygem-mixlib-cli \
		rubygem-mixlib-log>=1.3:devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=2.0:devel/rubygem-mixlib-shellout \
		rubygem-net-sftp>=2.1.2:security/rubygem-net-sftp \
		rubygem-net-ssh4>=2.9:security/rubygem-net-ssh4 \
		rubygem-net-ssh-multi>=1.2.1:security/rubygem-net-ssh-multi \
		rubygem-ohai8<13.0:sysutils/rubygem-ohai8 \
		rubygem-plist>=3.2:devel/rubygem-plist \
		rubygem-proxifier>=1.0:net/rubygem-proxifier \
		rubygem-rspec-core>=3.5:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=3.5:devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=3.5:devel/rubygem-rspec-mocks \
		rubygem-rspec_junit_formatter>0:devel/rubygem-rspec_junit_formatter \
		rubygem-serverspec>=2.7:sysutils/rubygem-serverspec \
		rubygem-specinfra>=2.10:sysutils/rubygem-specinfra \
		rubygem-syslog-logger>=1.6:sysutils/rubygem-syslog-logger \
		rubygem-uuidtools>=2.1.5:devel/rubygem-uuidtools \
		rubygem-builder>0:devel/rubygem-builder

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem python:env shebangfix

CONFLICTS_INSTALL=	rubygem-chef \
			rubygem-chef[0-9]*

SUB_LIST=	RUBY=${RUBY}
USE_RC_SUBR=	chef_client

SHEBANG_FILES=	spec/functional/assets/chefinittest \
		spec/functional/assets/testchefsubsys \
		lib/chef/provider/package/dnf/dnf_helper.py \
		tasks/bin/run_external_test

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/spec/data/apt/chef-integration-test*/debian/rules
	@${REINPLACE_CMD} -e 's|0.2.0|0.2|g' ${WRKSRC}/chef.gemspec

post-install:
	${INSTALL_MAN} ${WRKSRC}/distro/common/man/man1/*.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/distro/common/man/man8/*.8 ${STAGEDIR}${MANPREFIX}/man/man8/
	${MKDIR} ${STAGEDIR}/var/chef

.include <bsd.port.mk>

# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	vagrant
PORTVERSION=	2.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils rubygems devel

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Vagrant Virtual Machine Manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-bundler>=1.12.5:sysutils/rubygem-bundler \
		rubygem-main>=1.0:devel/rubygem-main
RUN_DEPENDS=	rubygem-bundler>=1.12.5:sysutils/rubygem-bundler \
		rubygem-childprocess>=0.6.0:devel/rubygem-childprocess \
		rubygem-erubis>=2.7.0:www/rubygem-erubis \
		rubygem-hashicorp-checkpoint>=0.1.1:www/rubygem-hashicorp-checkpoint \
		rubygem-i18n>=0.6.0:devel/rubygem-i18n \
		rubygem-listen>=3.1.5:devel/rubygem-listen \
		rubygem-log4r>=1.1.9:sysutils/rubygem-log4r \
		rubygem-net-scp>=1.2.0:security/rubygem-net-scp \
		rubygem-net-sftp>=2.1:security/rubygem-net-sftp \
		rubygem-net-ssh>=4.1.0:security/rubygem-net-ssh \
		rubygem-rb-kqueue>=0.2.0:devel/rubygem-rb-kqueue \
		rubygem-rest-client>=1.6.0:www/rubygem-rest-client \
		rubygem-wdm>=0.1.0:devel/rubygem-wdm \
		rubygem-winrm>=2.1:sysutils/rubygem-winrm \
		rubygem-winrm-elevated>=1.1:sysutils/rubygem-winrm-elevated \
		rubygem-winrm-fs>=1.0:sysutils/rubygem-winrm-fs \
		rubygem-ruby_dep>=0:devel/rubygem-ruby_dep

USE_GITHUB=	yes
GH_ACCOUNT=	mitchellh

USES=		shebangfix
SHEBANG_FILES=	plugins/hosts/darwin/scripts/install_virtualbox.sh \
		scripts/sign.sh \
		scripts/website_push_docs.sh \
		scripts/website_push_www.sh
USE_RUBY=	yes
GEMFILES=	vagrant-${PORTVERSION}.gem
RUBYGEMBIN=	gem${RUBY_SUFFIX}
PLIST_SUB+=	GEMS_DIR="lib/ruby/gems/${RUBY_VER}/" \
		GEM_BASE_DIR="lib/ruby/gems/${RUBY_VER}/gems" \
		DOC_DIR="lib/ruby/gems/${RUBY_VER}/doc" \
		PORTVERSION="${PORTVERSION}"
NO_ARCH=	yes

RUBYGEM_ARGS=	--no-ri --no-rdoc -l --no-update-sources \
		--install-dir ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER} \
		--ignore-dependencies --bindir=${STAGEDIR}${PREFIX}/bin
GEM_ENV+=	RB_USER_INSTALL=yes

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/bin/vagrant

do-build:
	(cd ${WRKSRC}; (${ECHO_CMD} -e "install:\n\techo\n") > Makefile)
	(cd ${WRKSRC}; ${SETENV} VAGRANT_INSTALLER_ENV=yes \
		${GEM_ENV} ${RUBYGEMBIN} build vagrant.gemspec)
	(cd ${WRKSRC}; ${SETENV} VAGRANT_INSTALLER_ENV=yes \
		${GEM_ENV} ${RUBYGEMBIN} install ${RUBYGEM_ARGS} \
		${GEMFILES} -- --build-args ${CONFIGURE_ARGS})
	${MKDIR} ${STAGEDIR}${DATADIR}/embedded/rgloader
	${INSTALL_DATA} ${FILESDIR}/cacert.pem \
		${STAGEDIR}${DATADIR}/embedded/cacert.pem
	${INSTALL_SCRIPT} ${FILESDIR}/loader.rb \
		${STAGEDIR}${DATADIR}/embedded/rgloader/loader.rb

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/doc

.include <bsd.port.mk>

# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	vagrant
PORTVERSION=	1.7.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils rubygems devel

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Vagrant Virtual Machine Manager

LICENSE=	MIT

BUILD_DEPENDS=	rubygem-builder32>=2.1.2:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-bundler17>=1.5.3:${PORTSDIR}/sysutils/rubygem-bundler17 \
		rubygem-main>=1.0:${PORTSDIR}/devel/rubygem-main
RUN_DEPENDS=	rubygem-bundler17>=1.5.3:${PORTSDIR}/sysutils/rubygem-bundler17 \
		rubygem-childprocess>=0.5.1:${PORTSDIR}/devel/rubygem-childprocess \
		rubygem-erubis>=2.7.0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-hashicorp-checkpoint>=0.1.4:${PORTSDIR}/www/rubygem-hashicorp-checkpoint \
		rubygem-i18n>=0.6.9:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-listen2>=2.8.0:${PORTSDIR}/devel/rubygem-listen2 \
		rubygem-log4r>=1.1.10:${PORTSDIR}/sysutils/rubygem-log4r \
		rubygem-net-scp>=1.1.0:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-net-sftp>=2.1:${PORTSDIR}/security/rubygem-net-sftp \
		rubygem-net-ssh>=2.6.6:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-nokogiri>=1.6.3.1:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-rb-kqueue>=0.2.2:${PORTSDIR}/devel/rubygem-rb-kqueue \
		rubygem-rest-client>=1.6.0:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-wdm>=0.1.0:${PORTSDIR}/devel/rubygem-wdm \
		rubygem-winrm>=1.1.3:${PORTSDIR}/sysutils/rubygem-winrm

USE_GITHUB=	yes
GH_ACCOUNT=	mitchellh

USE_RUBY=	yes
GEMFILES=	vagrant-${PORTVERSION}.gem
RUBYGEMBIN=	gem${RUBY_SUFFIX}
PLIST_SUB+=	GEMS_DIR="lib/ruby/gems/${RUBY_VER}/" \
		GEM_BASE_DIR="lib/ruby/gems/${RUBY_VER}/gems" \
		DOC_DIR="lib/ruby/gems/${RUBY_VER}/doc" \
		PORTVERSION="${PORTVERSION}"

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

PORTNAME=	vagrant
PORTVERSION=	2.4.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	sysutils rubygems devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vagrant Virtual Machine Manager
WWW=		https://www.vagrantup.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-bundler>=1.12.5:sysutils/rubygem-bundler \
		rubygem-main>=1.0:devel/rubygem-main
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		curl:ftp/curl \
		rubygem-bcrypt_pbkdf>=1.1:security/rubygem-bcrypt_pbkdf \
		rubygem-childprocess>=4.1.0:devel/rubygem-childprocess \
		rubygem-ed25519>=1.3.0:security/rubygem-ed25519 \
		rubygem-erubi>=0:www/rubygem-erubi \
		rubygem-googleapis-common-protos-types>=1.3.0:devel/rubygem-googleapis-common-protos-types \
		rubygem-grpc>=1.56.0:net/rubygem-grpc \
		rubygem-hashicorp-checkpoint>=0.1.5<0.2:www/rubygem-hashicorp-checkpoint \
		rubygem-i18n>=1.12,2<2,2:devel/rubygem-i18n \
		rubygem-ipaddr>=1.2.4:net/rubygem-ipaddr \
		rubygem-listen>=3.7<4:devel/rubygem-listen \
		rubygem-log4r>=1.1.9<1.1.11:sysutils/rubygem-log4r \
		rubygem-mime-types>=3.3:misc/rubygem-mime-types \
		rubygem-net-ftp>=0.2:ftp/rubygem-net-ftp \
		rubygem-net-scp>=4.0.0:security/rubygem-net-scp \
		rubygem-net-sftp>=4.0:security/rubygem-net-sftp \
		rubygem-net-ssh>=7.0.0:security/rubygem-net-ssh \
		rubygem-rb-kqueue>=0.2.0<0.3:devel/rubygem-rb-kqueue \
		rubygem-rexml>=3.2:textproc/rubygem-rexml \
		rubygem-rgl>=0.5.10:devel/rubygem-rgl \
		rubygem-rubyzip>=2.3.2:archivers/rubygem-rubyzip \
		rubygem-vagrant_cloud>=3.1.1<3.2:sysutils/rubygem-vagrant_cloud \
		rubygem-wdm>=0.1.1:devel/rubygem-wdm \
		rubygem-winrm>=2.3.6<3:sysutils/rubygem-winrm \
		rubygem-winrm-elevated>=1.2.3<2:sysutils/rubygem-winrm-elevated \
		rubygem-winrm-fs>=1.3.5<2:filesystems/rubygem-winrm-fs

USES=		cpe ruby shebangfix
CPE_VENDOR=	hashicorp
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GEM_ENV+=	RB_USER_INSTALL=yes

SHEBANG_FILES=	plugins/hosts/darwin/scripts/install_virtualbox.sh \
		scripts/sign.sh scripts/website_push_www.sh
GEMFILES=	vagrant-${PORTVERSION}.gem
RUBYGEMBIN=	gem

BUILD_TARGET=	${ARCH}-${OPSYS:tl}-${OSREL:R}

PLIST_SUB+=	BUILD_TARGET="${BUILD_TARGET}" \
		DOC_DIR="lib/ruby/gems/${RUBY_VER}/doc" \
		GEM_BASE_DIR="lib/ruby/gems/${RUBY_VER}/gems" \
		GEMS_DIR="lib/ruby/gems/${RUBY_VER}" \
		PORTVERSION="${PORTVERSION}"

RUBYGEM_ARGS=	-l --no-document --no-update-sources --install-dir \
		${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER} \
		--ignore-dependencies --bindir=${STAGEDIR}${PREFIX}/bin

OPTIONS_DEFINE=		BASH ZSH
OPTIONS_DEFAULT=	BASH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/vagrant
ZSH_PLIST_FILES=	share/share/zsh/site-functions/_vagrant

REMOVE_TARGETS=	.envrc .runner.sh .vimrc .yardopts flake.lock flake.nix Gemfile \
		gen.go go.mod go.sum Makefile Rakefile shell.nix \
		vagrant-config.hcl vagrant-spec.config.example.rb \
		vagrant.gemspec vagrant_ssl.so

REMOVE_TARGETS_EXT=	gem_make.out mkmf.log

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' \
		${WRKSRC}/bin/vagrant \
		${WRKSRC}/plugins/providers/virtualbox/action/network.rb \
		${WRKSRC}/templates/locales/en.yml

do-build:
	(cd ${WRKSRC}; (${ECHO_CMD} -e "install:\n\techo\n") > Makefile)
	(cd ${WRKSRC}; ${SETENV} VAGRANT_INSTALLER_ENV=yes \
		${GEM_ENV} ${RUBYGEMBIN} build vagrant.gemspec)
	(cd ${WRKSRC}; ${SETENV} VAGRANT_INSTALLER_ENV=yes \
		${GEM_ENV} ${RUBYGEMBIN} install ${RUBYGEM_ARGS} \
		${GEMFILES} -- ${CONFIGURE_ARGS})
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/build_info
	${MKDIR} ${STAGEDIR}${DATADIR}/embedded/rgloader
	${INSTALL_SCRIPT} ${FILESDIR}/loader.rb \
		${STAGEDIR}${DATADIR}/embedded/rgloader/loader.rb

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER} -name '*.so' -exec ${STRIP_CMD} {} +
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/doc
	${RM} -r ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/gems/${PORTNAME}-${PORTVERSION}/ext
	${RM} -r ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/gems/${PORTNAME}-${PORTVERSION}/nix
.for FILE in ${REMOVE_TARGETS}
	${RM} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/gems/${PORTNAME}-${PORTVERSION}/${FILE}
.endfor
.for FILE in ${REMOVE_TARGETS_EXT}
	${RM} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/extensions/${BUILD_TARGET}/${RUBY_VER}/${PORTNAME}-${PORTVERSION}/${FILE}
.endfor

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${RLN} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/gems/${PORTNAME}-${PORTVERSION}/contrib/bash/completion.sh ${STAGEDIR}${PREFIX}/share/bash-completion/completions/vagrant

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/share/zsh/site-functions
	${RLN} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/gems/${PORTNAME}-${PORTVERSION}/contrib/zsh/_vagrant ${STAGEDIR}${PREFIX}/share/share/zsh/site-functions

.include <bsd.port.post.mk>

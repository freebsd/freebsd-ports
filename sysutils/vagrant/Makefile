# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	vagrant
PORTVERSION=	1.6.5
PORTREVISION=	3
CATEGORIES=	sysutils rubygems devel
MASTER_SITES=	LOCAL/swills https://codeload.github.com/mitchellh/vagrant/legacy.tar.gz/v${PORTVERSION}?dummy=/

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Vagrant Virtual Machine Manager

LICENSE=	MIT

BUILD_DEPENDS=	rubygem-builder>=2.1.2:${PORTSDIR}/devel/rubygem-builder \
		rubygem-bundler>=1.5.3:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-main>=1.0:${PORTSDIR}/devel/rubygem-main
RUN_DEPENDS=	rubygem-main>=1.0:${PORTSDIR}/devel/rubygem-main \
		rubygem-akami>=1.0.0:${PORTSDIR}/www/rubygem-akami \
		rubygem-bundler>=1.5.3:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-ffi>=1.9.3:${PORTSDIR}/devel/rubygem-ffi \
		rubygem-childprocess>=0.5.1:${PORTSDIR}/devel/rubygem-childprocess \
		rubygem-erubis>=2.7.0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-gyoku>=0.4.6:${PORTSDIR}/devel/rubygem-gyoku \
		rubygem-hashicorp-checkpoint>=0.1.4:${PORTSDIR}/www/rubygem-hashicorp-checkpoint \
		rubygem-httpclient>=2.3.3:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-httpi>=0.9.0:${PORTSDIR}/www/rubygem-httpi \
		rubygem-i18n>=0.6.9:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-logging>=1.8.1:${PORTSDIR}/devel/rubygem-logging \
		rubygem-timers1>=1.1.0:${PORTSDIR}/devel/rubygem-timers1 \
		rubygem-celluloid>=0.15.2:${PORTSDIR}/devel/rubygem-celluloid \
		rubygem-rb-fsevent>=0.9.4:${PORTSDIR}/devel/rubygem-rb-fsevent \
		rubygem-rb-inotify>=0.9.3:${PORTSDIR}/devel/rubygem-rb-inotify \
		rubygem-listen>=2.4.1:${PORTSDIR}/devel/rubygem-listen \
		rubygem-log4r>=1.1.10:${PORTSDIR}/sysutils/rubygem-log4r \
		rubygem-net-ssh27=2.7.0,2:${PORTSDIR}/security/rubygem-net-ssh27 \
		rubygem-net-scp11=1.1.2:${PORTSDIR}/security/rubygem-net-scp11 \
		rubygem-rubyntlm01>=0.1.1:${PORTSDIR}/net/rubygem-rubyntlm01 \
		rubygem-nokogiri>=1.6.1:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-nori>=1.0.3:${PORTSDIR}/devel/rubygem-nori \
		rubygem-rack>=1.4.5:${PORTSDIR}/www/rubygem-rack \
		rubygem-savon>=0.9.5:${PORTSDIR}/www/rubygem-savon \
		rubygem-rb-kqueue>=0.2.2:${PORTSDIR}/devel/rubygem-rb-kqueue \
		rubygem-uuidtools>=2.1.2:${PORTSDIR}/devel/rubygem-uuidtools \
		rubygem-wasabi>=1.0.0:${PORTSDIR}/www/rubygem-wasabi \
		rubygem-winrm>=1.1.3:${PORTSDIR}/sysutils/rubygem-winrm \
		rubygem-wdm>=0.1.0:${PORTSDIR}/devel/rubygem-wdm

WRKSRC=		${WRKDIR}/mitchellh-vagrant-c38e17c
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

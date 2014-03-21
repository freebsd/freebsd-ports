# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	vagrant
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	sysutils rubygems devel
MASTER_SITES=	LOCAL/swills https://codeload.github.com/mitchellh/vagrant/legacy.tar.gz/v${PORTVERSION}?dummy=/

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Vagrant Virtual Machine Manager

LICENSE=	MIT

BUILD_DEPENDS=	rubygem-bundler>=1.5.3:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-main>=1.0:${PORTSDIR}/devel/rubygem-main
RUN_DEPENDS=	rubygem-main>=1.0:${PORTSDIR}/devel/rubygem-main \
		rubygem-bundler>=1.5.3:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-ffi>=1.9.3:${PORTSDIR}/devel/rubygem-ffi \
		rubygem-childprocess>=0.5.1:${PORTSDIR}/devel/rubygem-childprocess \
		rubygem-erubis>=2.7.0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-i18n>=0.6.9:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-timers>=1.1.0:${PORTSDIR}/devel/rubygem-timers \
		rubygem-celluloid>=0.15.2:${PORTSDIR}/devel/rubygem-celluloid \
		rubygem-rb-fsevent>=0.9.4:${PORTSDIR}/devel/rubygem-rb-fsevent \
		rubygem-rb-inotify>=0.9.3:${PORTSDIR}/devel/rubygem-rb-inotify \
		rubygem-listen>=2.4.1:${PORTSDIR}/devel/rubygem-listen \
		rubygem-log4r>=1.1.10:${PORTSDIR}/sysutils/rubygem-log4r \
		rubygem-net-ssh>=2.7.0:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-net-scp>=1.1.2:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-rb-kqueue>=0.2.2:${PORTSDIR}/devel/rubygem-rb-kqueue \
		rubygem-wdm>=0.1.0:${PORTSDIR}/devel/rubygem-wdm

WRKSRC=		${WRKDIR}/mitchellh-vagrant-6977e93
USE_RUBY=	yes
GEMFILES=	vagrant-1.5.1.gem
RUBYGEMBIN=	gem${RUBY_SUFFIX}
PLIST_SUB+=	GEMS_DIR="lib/ruby/gems/${RUBY_VER}/" \
		GEM_BASE_DIR="lib/ruby/gems/${RUBY_VER}/gems" \
		DOC_DIR="lib/ruby/gems/${RUBY_VER}/doc" \
		PORTVERSION="${PORTVERSION}"

RUBYGEM_ARGS=	--no-ri --no-rdoc -l --no-update-sources --install-dir ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER} --ignore-dependencies --bindir=${STAGEDIR}${PREFIX}/bin
GEM_ENV+=	RB_USER_INSTALL=yes

post-patch:
	@${RM} ${WRKSRC}/bin/vagrant.orig
	@${RM} ${WRKSRC}/vagrant.gemspec.orig

do-build:
	@(cd ${WRKSRC}; (${ECHO_CMD} -e "install:\n\techo\n") > Makefile)
	@(cd ${WRKSRC}; ${SETENV} VAGRANT_INSTALLER_ENV=yes ${GEM_ENV} ${RUBYGEMBIN} build vagrant.gemspec)
	@(cd ${WRKSRC}; ${SETENV} VAGRANT_INSTALLER_ENV=yes ${GEM_ENV} ${RUBYGEMBIN} install ${RUBYGEM_ARGS} ${GEMFILES} -- --build-args ${CONFIGURE_ARGS})

.include <bsd.port.pre.mk>

.if (${RUBY_VER} == "1.9")
IGNORE=		not supported with Ruby 1.9, Ruby 2.0 or 2.1 is needed
.endif

.include <bsd.port.post.mk>

# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	chef
PORTVERSION=	11.8.0
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	A systems integration framework. Client part

RUN_DEPENDS=	rubygem-bunny>=0.6.0:${PORTSDIR}/net/rubygem-bunny \
		rubygem-erubis>=0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-highline>=1.6.9:${PORTSDIR}/devel/rubygem-highline \
		rubygem-json>=1.4.4:${PORTSDIR}/devel/rubygem-json146 \
		rubygem-mixlib-authentication>=1.1.0:${PORTSDIR}/devel/rubygem-mixlib-authentication \
		rubygem-mixlib-cli>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=2.0.0:${PORTSDIR}/devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=1.2.0:${PORTSDIR}/devel/rubygem-mixlib-shellout \
		rubygem-moneta>=0:${PORTSDIR}/devel/rubygem-moneta \
		rubygem-net-ssh>=2.6.0:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-net-ssh-multi>=1.1.0:${PORTSDIR}/security/rubygem-net-ssh-multi \
		rubygem-ohai>=6.0:${PORTSDIR}/sysutils/rubygem-ohai \
		rubygem-rest-client>=1.0.4:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-treetop>=1.4.9:${PORTSDIR}/devel/rubygem-treetop \
		rubygem-uuidtools>=0:${PORTSDIR}/devel/rubygem-uuidtools \
		rubygem-yajl-ruby>=1.1.0:${PORTSDIR}/devel/rubygem-yajl-ruby \
		rubygem-erubis>=2.7.0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-diff-lcs>=1.2.4:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-chef-zero>=1.6.2:${PORTSDIR}/sysutils/rubygem-chef-zero \
		rubygem-pry>=0.9.0:${PORTSDIR}/devel/rubygem-pry \
		rubygem-puma>=1.6.2:${PORTSDIR}/www/rubygem-puma

USE_RUBY=		yes
USE_RUBYGEMS=		yes
USE_RUBY_FEATURES=	iconv
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/chef-client \
		bin/chef-solo \
		bin/shef \
		bin/knife \
		bin/chef-apply \
		bin/chef-service-manager \
		bin/chef-shell

MAN1=	chef-shell.1 knife-bootstrap.1 knife-client.1 knife-configure.1 \
	knife-cookbook-site.1 knife-cookbook.1 knife-data-bag.1 knife-delete.1 \
	knife-deps.1 knife-diff.1 knife-download.1 knife-edit.1 knife-environment.1 \
	knife-exec.1 knife-index-rebuild.1 knife-list.1 knife-node.1 knife-raw.1 \
	knife-recipe-list.1 knife-role.1 knife-search.1 knife-show.1 knife-ssh.1 \
	knife-status.1 knife-tag.1 knife-upload.1 knife-user.1 knife-xargs.1 knife.1

MAN8=	chef-client.8 chef-solo.8

SUB_LIST=	RUBY=${RUBY}
USE_RC_SUBR=	chef_client

OPTIONS_DEFINE=	PKGUPGRADE
PKGUPGRADE_DESC=	Use pkgupgrade as a default package provider
OPTIONS_DEFAULT=	PKGUPGRADE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPKGUPGRADE}
RUN_DEPENDS+=	bsdadminscripts>=0:${PORTSDIR}/sysutils/bsdadminscripts
.endif

post-install:
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/lib-chef-daemon.rb.patch
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/lib-chef-provider-service-freebsd.rb.patch
.if ${PORT_OPTIONS:MPKGUPGRADE}
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/lib-chef-provider-package-pkgupgrade.rb.patch
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/lib-chef-providers.rb.patch
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/lib-chef-resources.rb.patch
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/lib-chef-resource-pkgupgrade_package.rb.patch
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/lib-chef-platform-provider_mapping.rb.patch
.endif
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/lib-chef-handler-error_report.patch
	@${REINPLACE_CMD} -e 's@/etc@${PREFIX}/etc@' ${PREFIX}/${GEM_LIB_DIR}/lib/chef/application/solo.rb
	@${REINPLACE_CMD} -e 's@/etc@${PREFIX}/etc@' ${PREFIX}/${GEM_LIB_DIR}/lib/chef/application/client.rb
	@${REINPLACE_CMD} -e 's@/etc@${PREFIX}/etc@' ${PREFIX}/${GEM_LIB_DIR}/lib/chef/encrypted_data_bag_item.rb
	@${REINPLACE_CMD} -e 's@/etc@${PREFIX}/etc@' ${PREFIX}/${GEM_LIB_DIR}/lib/chef/config.rb
	@${REINPLACE_CMD} -e 's@/etc@${PREFIX}/etc@' ${PREFIX}/${GEM_LIB_DIR}/lib/chef/knife/core/ui.rb
	@${REINPLACE_CMD} -e 's@/etc@${PREFIX}/etc@' ${PREFIX}/${GEM_LIB_DIR}/lib/chef/knife/core/bootstrap_context.rb
	@${REINPLACE_CMD} -e 's@/etc@${PREFIX}/etc@' ${PREFIX}/${GEM_LIB_DIR}/lib/chef/knife/configure.rb
	@${FIND} ${PREFIX}/${GEM_LIB_DIR}/distro/common -type f -exec ${REINPLACE_CMD} -e 's@/etc@${PREFIX}/etc@' {} \;
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -name "*.orig" -delete
.if !defined(NO_INSTALL_MANPAGES)
.for n in 1 8
.for f in ${MAN${n}}
	${INSTALL_DATA} ${PREFIX}/${GEM_LIB_DIR}/distro/common/man/man${n}/${f} ${PREFIX}/man/man${n}
.endfor
.endfor
.endif

.include <bsd.port.mk>

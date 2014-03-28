# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	chef
PORTVERSION=	11.10.4
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Systems integration framework. Client part

RUN_DEPENDS=	rubygem-chef-zero>=0.0.0:${PORTSDIR}/sysutils/rubygem-chef-zero \
		rubygem-diff-lcs>=0.0.0:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-erubis>=0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-highline>=1.6.9:${PORTSDIR}/devel/rubygem-highline \
		rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json \
		rubygem-mixlib-authentication>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-authentication \
		rubygem-mixlib-cli>=1.4.0:${PORTSDIR}/devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=2.1.0:${PORTSDIR}/devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-shellout \
		rubygem-net-ssh>=2.6:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-net-ssh-multi>=1.1.0:${PORTSDIR}/security/rubygem-net-ssh-multi \
		rubygem-ohai>=6.0.0:${PORTSDIR}/sysutils/rubygem-ohai \
		rubygem-pry>=0.9.0:${PORTSDIR}/devel/rubygem-pry \
		rubygem-puma16>=1.6.0:${PORTSDIR}/www/rubygem-puma16 \
		rubygem-rest-client>=1.0.4:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-yajl-ruby>=1.1.0:${PORTSDIR}/devel/rubygem-yajl-ruby

USE_RUBY=		yes
USE_RUBYGEMS=		yes
USE_RUBY_FEATURES=	iconv
RUBYGEM_AUTOPLIST=	yes

SUB_LIST=	RUBY=${RUBY}
USE_RC_SUBR=	chef_client

post-install:
.for M1 in chef-shell.1 knife-bootstrap.1 knife-client.1 knife-configure.1 knife-cookbook-site.1 \
	knife-cookbook.1 knife-data-bag.1 knife-delete.1 knife-deps.1 knife-diff.1 \
	knife-download.1 knife-edit.1 knife-environment.1 knife-exec.1 knife-index-rebuild.1 \
	knife-list.1 knife-node.1 knife-raw.1 knife-recipe-list.1 knife-role.1 knife-search.1 \
	knife-show.1 knife-ssh.1 knife-status.1 knife-tag.1 knife-upload.1 knife-user.1 \
	knife-xargs.1 knife.1
	@cd ${WRKSRC}/distro/common/man/man1 && ${INSTALL_MAN} ${M1} ${STAGEDIR}${MANPREFIX}/man/man1/
.endfor
.for M8 in chef-client.8 chef-solo.8
	@cd ${WRKSRC}/distro/common/man/man8 && ${INSTALL_MAN} ${M8} ${STAGEDIR}${MANPREFIX}/man/man8/
.endfor

.include <bsd.port.mk>

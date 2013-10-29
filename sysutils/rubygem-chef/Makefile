# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	chef
PORTVERSION=	11.6.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Systems integration framework. Client part

RUN_DEPENDS=	rubygem-erubis>=0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-highline>=1.6.9:${PORTSDIR}/devel/rubygem-highline \
		rubygem-json146>=1.4.4:${PORTSDIR}/devel/rubygem-json146 \
		rubygem-mixlib-authentication>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-authentication \
		rubygem-mixlib-cli>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=1.1.2:${PORTSDIR}/devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=1.0.0:${PORTSDIR}/devel/rubygem-mixlib-shellout \
		rubygem-net-ssh>=2.6:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-net-ssh-multi>=1.1.0:${PORTSDIR}/security/rubygem-net-ssh-multi \
		rubygem-ohai>=0.6.0:${PORTSDIR}/sysutils/rubygem-ohai \
		rubygem-rest-client>=1.0.4:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-yajl-ruby>=1.1.0:${PORTSDIR}/devel/rubygem-yajl-ruby

USE_RUBY=		yes
USE_RUBYGEMS=		yes
USE_RUBY_FEATURES=	iconv
RUBYGEM_AUTOPLIST=	yes

SUB_LIST=	RUBY=${RUBY}
USE_RC_SUBR=	chef_client

NO_STAGE=	yes
post-install:
.for n in 1 8
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/distro/common/man/man${n}/* ${STAGEDIR}${PREFIX}/man/man${n}/
.endfor

.include <bsd.port.mk>

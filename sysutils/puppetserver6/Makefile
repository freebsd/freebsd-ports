# $FreeBSD$

PORTNAME=	puppetserver
PORTVERSION=	6.12.0
CATEGORIES=	sysutils java
MASTER_SITES=	https://downloads.puppetlabs.com/puppet/:upstream \
		https://raw.githubusercontent.com/jruby/jruby/fb3ba4b3543b72e735ba53b51e6b7ec8a9916e1b/lib/ruby/stdlib/ffi/:ffi
PKGNAMESUFFIX=	6
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:upstream \
		ffi.rb:ffi
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Puppet Server running in the JVM

LICENSE=	APACHE20

RUN_DEPENDS=	bash>=0:shells/bash \
		puppet6>=0:sysutils/puppet6 \
		rubygem-puppetserver-ca>=1:sysutils/rubygem-puppetserver-ca \
		rubygem-semantic_puppet>=1:devel/rubygem-semantic_puppet \
		sudo>=1:security/sudo

USES=		shebangfix
USE_RC_SUBR=	puppetserver

USE_JAVA=	yes
USE_RUBY=	yes
NO_ARCH=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.8+

CONFLICTS_INSTALL=	puppetserver-* puppetserver5-*

SHEBANG_FILES=  ext/bin/puppetserver

USERS=		puppet
GROUPS=		puppet

SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	pkg-message

pre-patch:
	${CP} ${_DISTDIR}/ffi.rb ${WRKSRC}

post-patch:
.for file in ext/config/logback.xml ext/config/request-logging.xml \
	ext/config/conf.d/global.conf ext/config/conf.d/puppetserver.conf \
	ext/config/conf.d/web-routes.conf ext/config/conf.d/webserver.conf \
	ext/config/conf.d/auth.conf ext/config/services.d/ca.cfg \
	ext/system-config/services.d/bootstrap.cfg ext/bin/puppetserver \
	ext/cli_defaults/cli-defaults.sh ext/cli/foreground
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%RUBY_SITELIBDIR%%|${RUBY_SITELIBDIR}|' \
		-e 's|%%RUBY_VER%%|${RUBY_VER}|' \
		-e 's|%%JAVA%%|${JAVA}|' \
		-e 's|%%ETCDIR%%|${ETCDIR}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|#!/opt/puppetlabs/puppet/bin/ruby|#!${RUBY}|' \
		${WRKSRC}/ext/cli/ca

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/cli/apps
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d
	@${MKDIR} ${STAGEDIR}${ETCDIR}/services.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppet/code
	@${MKDIR} ${STAGEDIR}/var/log/puppetserver
	@${MKDIR} ${STAGEDIR}/var/puppet/server
	@${MKDIR} ${STAGEDIR}/var/puppet/server/data
	@${MKDIR} ${STAGEDIR}/var/run/puppetserver
	${INSTALL_DATA} ${WRKSRC}/puppet-server-release.jar ${STAGEDIR}${DATADIR}/puppet-server-release.jar
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/global.conf ${STAGEDIR}${ETCDIR}/conf.d/global.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/logback.xml ${STAGEDIR}${ETCDIR}/logback.xml.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/request-logging.xml ${STAGEDIR}${ETCDIR}/request-logging.xml.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/puppetserver.conf ${STAGEDIR}${ETCDIR}/conf.d/puppetserver.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/web-routes.conf ${STAGEDIR}${ETCDIR}/conf.d/web-routes.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/webserver.conf ${STAGEDIR}${ETCDIR}/conf.d/webserver.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/auth.conf ${STAGEDIR}${ETCDIR}/conf.d/auth.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/metrics.conf ${STAGEDIR}${ETCDIR}/conf.d/metrics.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/services.d/ca.cfg ${STAGEDIR}${ETCDIR}/services.d/ca.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/ext/system-config/services.d/bootstrap.cfg ${STAGEDIR}${ETCDIR}/services.d/bootstrap.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/ext/bin/puppetserver ${STAGEDIR}${PREFIX}/bin/puppetserver
	${INSTALL_DATA} ${WRKSRC}/ext/ezbake-functions.sh ${STAGEDIR}${DATADIR}/ezbake-functions.sh
	${INSTALL_DATA} ${WRKSRC}/ext/cli/ca ${STAGEDIR}${DATADIR}/cli/apps/ca
	${INSTALL_DATA} ${WRKSRC}/ext/cli/foreground ${STAGEDIR}${DATADIR}/cli/apps/foreground
	${INSTALL_DATA} ${WRKSRC}/ext/cli/gem ${STAGEDIR}${DATADIR}/cli/apps/gem
	${INSTALL_DATA} ${WRKSRC}/ext/cli/irb ${STAGEDIR}${DATADIR}/cli/apps/irb
	${INSTALL_DATA} ${WRKSRC}/ext/cli/reload ${STAGEDIR}${DATADIR}/cli/apps/reload
	${INSTALL_DATA} ${WRKSRC}/ext/cli/ruby ${STAGEDIR}${DATADIR}/cli/apps/ruby
	${INSTALL_DATA} ${WRKSRC}/ext/cli/start ${STAGEDIR}${DATADIR}/cli/apps/start
	${INSTALL_DATA} ${WRKSRC}/ext/cli/stop ${STAGEDIR}${DATADIR}/cli/apps/stop
	${INSTALL_DATA} ${WRKSRC}/ext/cli_defaults/cli-defaults.sh ${STAGEDIR}${DATADIR}/cli/cli-defaults.sh
	${INSTALL_DATA} ${WRKSRC}/ffi.rb ${STAGEDIR}${DATADIR}/lib

.include <bsd.port.mk>

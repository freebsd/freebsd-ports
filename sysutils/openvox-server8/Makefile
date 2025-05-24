PORTNAME=	openvox-server
PORTVERSION=	8.8.1
CATEGORIES=	sysutils java
MASTER_SITES=	https://artifacts.voxpupuli.org/${PORTNAME}/${PORTVERSION}/
PKGNAMESUFFIX=	8

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Puppet Server running in the JVM
WWW=		https://docs.puppetlabs.com/puppetserver/latest/services_master_puppetserver.html

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=Bundled JNI only support some architectures

RUN_DEPENDS=	bash>=0:shells/bash \
		openvox-agent8>=8.0:sysutils/openvox-agent8 \
		rubygem-openvoxserver-ca>=1:sysutils/rubygem-openvoxserver-ca \
		rubygem-semantic_puppet>=1:devel/rubygem-semantic_puppet \
		sudo>=1:security/sudo

USES=		ruby java shebangfix
JAVA_VERSION=	11+
USE_RC_SUBR=	puppetserver
WRKSRC=		${WRKDIR}/puppetserver-${PORTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

CONFLICTS_INSTALL=	openvox-server[0-9] puppetserver[0-9]

SHEBANG_FILES=	ext/bin/puppetserver

USERS=		puppet
GROUPS=		puppet

DATADIR=	${PREFIX}/share/puppetserver
ETCDIR=		${PREFIX}/etc/puppetserver

SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	pkg-message

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
		${WRKSRC}/ext/cli/ca \
		${WRKSRC}/ext/cli/dropsonde

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/cli/apps
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d
	@${MKDIR} ${STAGEDIR}${ETCDIR}/services.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppet/code
	@${MKDIR} ${STAGEDIR}/var/log/puppetserver
	@${MKDIR} ${STAGEDIR}/var/puppet/server
	@${MKDIR} ${STAGEDIR}/var/puppet/server/data
	@${MKDIR} ${STAGEDIR}/var/puppetserver
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

.include <bsd.port.mk>

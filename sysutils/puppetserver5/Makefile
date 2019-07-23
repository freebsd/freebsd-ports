# $FreeBSD$

PORTNAME=	puppetserver
PORTVERSION=	5.3.9
CATEGORIES=	sysutils java
MASTER_SITES=	https://downloads.puppetlabs.com/puppet/
PKGNAMESUFFIX=	5

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Puppet Server running in the JVM

LICENSE=	APACHE20

BROKEN_FreeBSD_12=	Does not start. See PR 233766
BROKEN_FreeBSD_13=	Does not start. See PR 233766

RUN_DEPENDS=	bash>=0:shells/bash \
		puppet5>=0:sysutils/puppet5

USES=		shebangfix
USE_RC_SUBR=	puppetserver

USE_JAVA=	yes
USE_RUBY=	yes
NO_ARCH=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.8+

CONFLICTS_INSTALL=	puppetserver-* puppetserver6-*

SHEBANG_FILES=  ext/bin/puppetserver

USERS=		puppet
GROUPS=		puppet

SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	pkg-message

OPTIONS_DEFAULT=	CFACTER
OPTIONS_RADIO=		FACTER
OPTIONS_RADIO_FACTER=	CFACTER RFACTER

RFACTER_DESC=	Use facter 2.x (written in Ruby)
CFACTER_DESC=	Use facter 3.x (experimental rewrite in C++)

RFACTER_RUN_DEPENDS=	rubygem-facter>=2.0:sysutils/rubygem-facter

CFACTER_RUN_DEPENDS=	facter>=3.0:sysutils/facter

post-patch:
.for file in ext/config/logback.xml ext/config/request-logging.xml \
	ext/config/conf.d/global.conf ext/config/conf.d/puppetserver.conf \
	ext/config/conf.d/web-routes.conf ext/config/conf.d/webserver.conf \
	ext/config/conf.d/auth.conf ext/config/services.d/ca.cfg \
	ext/system-config/services.d/bootstrap.cfg ext/bin/puppetserver \
	ext/cli_defaults/cli-defaults.sh
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%RUBY_SITELIBDIR%%|${RUBY_SITELIBDIR}|' \
		-e 's|%%RUBY_VER%%|${RUBY_VER}|' \
		-e 's|%%JAVA%%|${JAVA}|' \
		-e 's|%%ETCDIR%%|${ETCDIR}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/${file}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/cli/apps
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d
	@${MKDIR} ${STAGEDIR}${ETCDIR}/services.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppet/code
	@${MKDIR} ${STAGEDIR}/var/log/puppetserver
	@${MKDIR} ${STAGEDIR}/var/puppet/server
	${INSTALL_DATA} ${WRKSRC}/puppet-server-release.jar ${STAGEDIR}${DATADIR}/puppet-server-release.jar
	${INSTALL_DATA} ${WRKSRC}/jruby-9k.jar ${STAGEDIR}${DATADIR}/jruby-9k.jar
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
	${INSTALL_DATA} ${WRKSRC}/ext/cli/foreground ${STAGEDIR}${DATADIR}/cli/apps/foreground
	${INSTALL_DATA} ${WRKSRC}/ext/cli/gem ${STAGEDIR}${DATADIR}/cli/apps/gem
	${INSTALL_DATA} ${WRKSRC}/ext/cli/irb ${STAGEDIR}${DATADIR}/cli/apps/irb
	${INSTALL_DATA} ${WRKSRC}/ext/cli/reload ${STAGEDIR}${DATADIR}/cli/apps/reload
	${INSTALL_DATA} ${WRKSRC}/ext/cli/ruby ${STAGEDIR}${DATADIR}/cli/apps/ruby
	${INSTALL_DATA} ${WRKSRC}/ext/cli/start ${STAGEDIR}${DATADIR}/cli/apps/start
	${INSTALL_DATA} ${WRKSRC}/ext/cli/stop ${STAGEDIR}${DATADIR}/cli/apps/stop
	${INSTALL_DATA} ${WRKSRC}/ext/cli_defaults/cli-defaults.sh ${STAGEDIR}${DATADIR}/cli/cli-defaults.sh

.include <bsd.port.mk>

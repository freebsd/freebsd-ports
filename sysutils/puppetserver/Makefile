# $FreeBSD$

PORTNAME=	puppetserver
PORTVERSION=	2.7.1
CATEGORIES=	sysutils java
MASTER_SITES=	http://downloads.puppetlabs.com/puppet/

MAINTAINER=	freebsd@zleslie.info
COMMENT=	Puppet Server running in the JVM

LICENSE=	APACHE20

RUN_DEPENDS=	bash>=0:shells/bash \
		puppet4>=0:sysutils/puppet4
BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake

USE_RC_SUBR=	puppetserver

USE_JAVA=	yes
USE_RUBY=	yes
NO_ARCH=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.7+

USERS=		puppet
GROUPS=		puppet

SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	pkg-message

PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFAULT=	RFACTER
OPTIONS_RADIO=		FACTER
OPTIONS_RADIO_FACTER=	CFACTER RFACTER

RFACTER_DESC=	Use facter 2.x (written in Ruby)
CFACTER_DESC=	Use facter 3.x (experimental rewrite in C++)

RFACTER_BUILD_DEPENDS=	rubygem-facter>=2.0:sysutils/rubygem-facter
RFACTER_RUN_DEPENDS=	rubygem-facter>=2.0:sysutils/rubygem-facter

CFACTER_BUILD_DEPENDS=	facter>=3.0:sysutils/facter
CFACTER_RUN_DEPENDS=	facter>=3.0:sysutils/facter

post-patch:
.for file in ext/config/logback.xml ext/config/request-logging.xml \
	ext/config/conf.d/global.conf ext/config/conf.d/puppetserver.conf \
	ext/config/conf.d/web-routes.conf ext/config/conf.d/webserver.conf \
	ext/config/conf.d/auth.conf ext/config/services.d/ca.cfg \
	ext/system-config/services.d/bootstrap.cfg ext/bin/puppetserver
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%RUBY_SITELIBDIR%%|${RUBY_SITELIBDIR}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%RUBY_VER%%|${RUBY_VER}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%JAVA%%|${JAVA}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%ETCDIR%%|${ETCDIR}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|" ${WRKSRC}/${file}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/cli
	@${MKDIR} ${STAGEDIR}${DATADIR}/cli/apps
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d
	@${MKDIR} ${STAGEDIR}${ETCDIR}/services.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppet/code
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}/var/log/puppetserver
	@${MKDIR} ${STAGEDIR}/var/puppet/server
	${INSTALL_DATA} ${WRKSRC}/puppet-server-release.jar ${STAGEDIR}${DATADIR}/puppet-server-release.jar
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/global.conf ${STAGEDIR}${ETCDIR}/conf.d/global.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/logback.xml ${STAGEDIR}${ETCDIR}/logback.xml.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/request-logging.xml ${STAGEDIR}${ETCDIR}/request-logging.xml.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/puppetserver.conf ${STAGEDIR}${ETCDIR}/conf.d/puppetserver.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/web-routes.conf ${STAGEDIR}${ETCDIR}/conf.d/web-routes.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/webserver.conf ${STAGEDIR}${ETCDIR}/conf.d/webserver.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/auth.conf ${STAGEDIR}${ETCDIR}/conf.d/auth.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/services.d/ca.cfg ${STAGEDIR}${ETCDIR}/services.d/ca.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/ext/system-config/services.d/bootstrap.cfg ${STAGEDIR}${ETCDIR}/services.d/bootstrap.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/ext/bin/puppetserver ${STAGEDIR}${PREFIX}/bin/puppetserver
	${INSTALL_DATA} ${WRKSRC}/ext/cli/foreground ${STAGEDIR}${DATADIR}/cli/apps/foreground
	${INSTALL_DATA} ${WRKSRC}/ext/cli/gem ${STAGEDIR}${DATADIR}/cli/apps/gem
	${INSTALL_DATA} ${WRKSRC}/ext/cli/irb ${STAGEDIR}${DATADIR}/cli/apps/irb
	${INSTALL_DATA} ${WRKSRC}/ext/cli/ruby ${STAGEDIR}${DATADIR}/cli/apps/ruby

.include <bsd.port.mk>

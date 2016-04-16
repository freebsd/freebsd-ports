# $FreeBSD$

PORTNAME=	puppetserver
PORTVERSION=	2.2.1
CATEGORIES=	sysutils java
MASTER_SITES=	http://downloads.puppetlabs.com/puppet/

MAINTAINER=	xaque208@gmail.com
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
.for file in ext/config/bootstrap.cfg ext/config/logback.xml \
	ext/config/request-logging.xml \
	ext/config/conf.d/global.conf ext/config/conf.d/puppetserver.conf \
	ext/config/conf.d/web-routes.conf ext/config/conf.d/webserver.conf \
	ext/config/conf.d/auth.conf
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%RUBY_SITELIBDIR%%|${RUBY_SITELIBDIR}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%RUBY_VER%%|${RUBY_VER}|" ${WRKSRC}/${file}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppet/code
	${MKDIR} ${STAGEDIR}/var/log/puppetserver
	${INSTALL_DATA} ${WRKSRC}/puppet-server-release.jar ${STAGEDIR}${DATADIR}/puppetserver.jar
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/global.conf ${STAGEDIR}${ETCDIR}/conf.d/global.conf
	${INSTALL_DATA} ${WRKSRC}/ext/config/logback.xml ${STAGEDIR}${ETCDIR}/logback.xml
	${INSTALL_DATA} ${WRKSRC}/ext/config/bootstrap.cfg ${STAGEDIR}${ETCDIR}/bootstrap.cfg
	${INSTALL_DATA} ${WRKSRC}/ext/config/request-logging.xml ${STAGEDIR}${ETCDIR}/request-logging.xml
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/puppetserver.conf ${STAGEDIR}${ETCDIR}/conf.d/puppetserver.conf
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/web-routes.conf ${STAGEDIR}${ETCDIR}/conf.d/web-routes.conf
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/webserver.conf ${STAGEDIR}${ETCDIR}/conf.d/webserver.conf
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/auth.conf ${STAGEDIR}${ETCDIR}/conf.d/auth.conf

.include <bsd.port.mk>

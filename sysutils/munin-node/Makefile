PORTNAME=	munin
PORTVERSION=	${MUNIN_VERSION}
PORTREVISION=	0
CATEGORIES=	sysutils perl5
PKGNAMESUFFIX=	-node

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Node-specific part of Munin
WWW=		https://munin-monitoring.org/

LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		munin-common>=${MUNIN_VERSION}:sysutils/munin-common \
		p5-DateTime-HiRes>=0:devel/p5-DateTime-HiRes \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Module-Build>=0:devel/p5-Module-Build \
		p5-Net-Server>=0:net/p5-Net-Server
RUN_DEPENDS=	bash:shells/bash \
		munin-common>=${MUNIN_VERSION}:sysutils/munin-common \
		p5-Cache-Cache>=0:devel/p5-Cache-Cache \
		p5-DateTime-HiRes>=0:devel/p5-DateTime-HiRes \
		p5-libwww>=0:www/p5-libwww \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Net-CIDR>=0:net-mgmt/p5-Net-CIDR \
		p5-Net-Server>=0:net/p5-Net-Server

USES=		cpe gmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	munin-monitoring
USE_RC_SUBR=	munin-asyncd munin-node

SHEBANG_FILES=	node/bin/munindoc node/sbin/munin-node \
		node/sbin/munin-node-configure node/sbin/munin-run

.include "${.CURDIR}/../munin-common/munin.mk"

ALL_TARGET=	build-node build-plugins build/node/_bin/munin-async \
		build/node/_bin/munin-asyncd
INSTALL_TARGET=	install-node-prime install-async-prime install-plugins-prime
REINPLACE_ARGS=	-i ""
NO_ARCH=	yes

PORTSCOUT=	ignore:1

SUB_FILES=	pkg-message plugins.conf

OPTIONS_DEFINE=		JAVA PERL PYTHON SNMP
OPTIONS_DEFAULT=	PERL PYTHON SNMP
OPTIONS_SUB=		yes

JAVA_DESC=	Include JAVA plugins
PERL_DESC=	Include all Perl modules (adds dependencies)
PYTHON_DESC=	Include Python plugins
SNMP_DESC=	Include SNMP plugins

JAVA_USE=		JAVA=yes
JAVA_INSTALL_TARGET=	install-plugins-java
JAVA_VARS=		JAVA_BUILD=yes \
			JAVA_RUN=yes

PERL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg \
			p5-Net-DNS>=0:dns/p5-Net-DNS \
			p5-Net-IP>=0:net-mgmt/p5-Net-IP \
			p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
			p5-XML-Parser>=0:textproc/p5-XML-Parser

PYTHON_USES=	python

SNMP_BUILD_DEPENDS=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP
SNMP_RUN_DEPENDS=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/node/sbin/munin-node \
		${WRKSRC}/node/sbin/munin-node-configure \
		${WRKSRC}/node/sbin/munin-run
	@${RM}  ${WRKSRC}/node/sbin/munin-node.bak \
		${WRKSRC}/node/sbin/munin-node-configure.bak \
		${WRKSRC}/node/sbin/munin-run.bak
	@${REINPLACE_CMD} \
		-e 's|^\(BASH[[:space:]]*:=\).*|\1 ${bash_CMD}|' \
		-e 's|^\(JAVARUN[[:space:]]*:=\).*|\1 ${java_CMD}|' \
		-e 's|^\(PERL[[:space:]]*:=\).*|\1 ${perl_CMD}|' \
		-e 's|^\(PYTHON[[:space:]]*:=\).*|\1 ${python_CMD}|' \
		-e 's|^\(RUBY[[:space:]]*:=\).*|\1 ${ruby_CMD}|' \
		${WRKSRC}/Makefile.config
	@${FIND} ${WRKSRC}/node/sbin -type f -name "*.orig" -delete

post-install:
	${MKDIR} ${STAGEDIR}${DBDIR}/plugin-state ${STAGEDIR}${SPOOLDIR}/async
	${INSTALL_SCRIPT} ${.CURDIR}/plugins/* ${STAGEDIR}${DATADIR}/plugins/
	${INSTALL_DATA} ${WRKSRC}/build/node/munin-node.conf \
		${STAGEDIR}${ETCDIR}/munin-node.conf.sample
	${INSTALL_DATA} ${WRKDIR}/plugins.conf \
		${STAGEDIR}${ETCDIR}/plugins.conf.sample
	(cd ${WRKSRC}/node/blib/bindoc; \
		${INSTALL_MAN} munin-node-configure.1 munin-node.1 munin-run.1 ${STAGEDIR}${PREFIX}/share/man/man1; \
	)
	(cd ${WRKSRC}/build/doc; \
		${INSTALL_MAN} munin-node.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5; \
		${INSTALL_MAN} munin.8 ${STAGEDIR}${PREFIX}/share/man/man8; \
	)
	${INSTALL_DATA} ${FILESDIR}/newsyslog ${STAGEDIR}${ETCDIR}/munin-node.newsyslog

.include <bsd.port.mk>

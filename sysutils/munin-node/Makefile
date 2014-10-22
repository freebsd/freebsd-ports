# Created by: Lupe Christoph <lupe@lupe-christoph.de>
# $FreeBSD$

PORTNAME=	munin
PORTVERSION=	${MUNIN_VERSION}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MUNIN_SITES}
PKGNAMESUFFIX=	-node

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Node-specific part of Munin

BUILD_DEPENDS=	p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build \
		p5-DateTime-HiRes>=0:${PORTSDIR}/devel/p5-DateTime-HiRes \
		munin-common>=0:${PORTSDIR}/sysutils/munin-common \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-DateTime-HiRes>=0:${PORTSDIR}/devel/p5-DateTime-HiRes \
		munin-common>=0:${PORTSDIR}/sysutils/munin-common \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-Net-CIDR>=0:${PORTSDIR}/net-mgmt/p5-Net-CIDR \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		bash:${PORTSDIR}/shells/bash

USES=		gmake perl5 shebangfix
PKGMESSAGE=	${WRKDIR}/pkg-message
REINPLACE_ARGS=	-i ""
SHEBANG_FILES=	node/sbin/munin-node node/sbin/munin-sched \
		node/sbin/munin-run node/sbin/munin-node-configure

.include "${.CURDIR}/../munin-common/munin.mk"

DISTINFO_FILE=	${MUNIN_DISTINFO}
EXTRA_PATCHES+=	${MUNIN_PATCHES}
ALL_TARGET=	build-node build-plugins
INSTALL_TARGET=	install-node-prime install-plugins-prime
NO_ARCH=	yes

OPTIONS_DEFINE=	SNMP JAVA
OPTIONS_DEFAULT=	SNMP
OPTIONS_SUB=	yes
SNMP_DESC=	Include SNMP plugins
JAVA_DESC=	Include JAVA plugins

SNMP_BUILD_DEPENDS+=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP
SNMP_RUN_DEPENDS+=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP
JAVA_USE=	java=yes
JAVA_INSTALL_TARGET=	install-plugins-java
JAVA_BUILD=	yes
JAVA_RUN=	yes

SUB_FILES=	pkg-message plugins.conf
USE_RC_SUBR=	munin-node munin-sched

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/node/sbin/munin-node \
		${WRKSRC}/node/sbin/munin-node-configure \
		${WRKSRC}/node/sbin/munin-run
	@${REINPLACE_CMD} \
		-e 's|^\(BASH[[:space:]]*:=\).*|\1 ${bash_CMD}|' \
		-e 's|^\(JAVARUN[[:space:]]*:=\).*|\1 ${java_CMD}|' \
		-e 's|^\(PERL[[:space:]]*:=\).*|\1 ${perl_CMD}|' \
		-e 's|^\(PYTHON[[:space:]]*:=\).*|\1 ${python_CMD}|' \
		-e 's|^\(RUBY[[:space:]]*:=\).*|\1 ${ruby_CMD}|' \
		${WRKSRC}/Makefile.config
	@${FIND} ${WRKSRC}/node/sbin -type f -name "*.orig" -delete

post-install:
	${MKDIR} ${STAGEDIR}${DBDIR}/plugin-state
	${INSTALL_SCRIPT} ${WRKDIR}/munin-node \
		${STAGEDIR}${PREFIX}/etc/rc.d/munin-node
	${INSTALL_DATA} ${WRKSRC}/build/node/munin-node.conf \
		${STAGEDIR}${ETCDIR}/munin-node.conf.sample
	${INSTALL_DATA} ${WRKDIR}/plugins.conf \
		${STAGEDIR}${ETCDIR}/plugin-conf.d/plugins.conf.sample
	(cd ${WRKSRC}/node/blib/bindoc; \
		${INSTALL_MAN} munin-node-configure.1 munin-node.1 munin-run.1 munin-sched.1 munindoc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1; \
	)
	(cd ${WRKSRC}/build/doc; \
		${INSTALL_MAN} munin-node.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5; \
		${INSTALL_MAN} munin.8 ${STAGEDIR}${MAN8PREFIX}/man/man8; \
	)

.include <bsd.port.mk>

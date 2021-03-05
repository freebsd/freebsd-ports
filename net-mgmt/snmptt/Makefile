# $FreeBSD$

PORTNAME=	snmptt
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nistor@snickers.org
COMMENT=	SNMP trap handler/translator/swiss-army-knife

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	net-snmp>=0:net-mgmt/net-snmp \
		p5-Config-IniFiles>=0:devel/p5-Config-IniFiles

NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix tar:tgz
USE_RC_SUBR=	snmptt
SUB_LIST=	PERL=${PERL}

PORTDOCS=	faqs.html index.html layout1.css snmptt.html \
		snmpttconvert.html snmpttconvertmib.html

USERS=	snmptt
GROUPS=	snmptt

OPTIONS_DEFINE=	DOCS

SCRIPTS=	snmptt snmptt-net-snmp-test snmpttconvert \
		snmpttconvertmib snmptthandler

SHEBANG_FILES=	${SCRIPTS}

post-patch:
	${REINPLACE_CMD} -e "s|/var/run|/var/run/${PORTNAME}|" \
	-e "s|/etc|${PREFIX}/etc|" ${WRKSRC}/snmptt.ini

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/snmp
	${INSTALL_DATA} ${WRKSRC}/snmptt.ini ${STAGEDIR}${PREFIX}/etc/snmp/snmptt.ini.sample
	${INSTALL_DATA} ${WRKSRC}/examples/snmptt.conf.generic \
		${STAGEDIR}${PREFIX}/etc/snmp/snmptt.conf.generic.sample
	${INSTALL_DATA} ${FILESDIR}/newsyslog-snmptt.conf \
		${STAGEDIR}${PREFIX}/etc/snmp/newsyslog-snmptt.conf.sample
	@${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	@${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}
	@${MKDIR} ${STAGEDIR}/var/spool/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

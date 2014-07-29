# $FreeBSD$

PORTNAME=	snmptt
PORTVERSION=	1.4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nistor@snickers.org
COMMENT=	SNMP trap handler/translator/swiss-army-knife

USES=		perl5 shebangfix tar:tgz
USE_RC_SUBR=	snmptt

RUN_DEPENDS=	net-snmp>=0:${PORTSDIR}/net-mgmt/net-snmp \
		p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced \
		p5-Text-ParseWords>=0:${PORTSDIR}/textproc/p5-Text-ParseWords \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes

DOCS=		faqs.html index.html layout1.css snmptt.html \
		snmpttconvert.html snmpttconvertmib.html

SCRIPTS=	snmptt snmptt-net-snmp-test snmpttconvert \
		snmpttconvertmib snmptthandler

SHEBANG_FILES=	${SCRIPTS}

.include <bsd.port.pre.mk>

do-build:
	@echo Skipping building ${PORTNAME}

do-install:
	@echo Installing ${PORTNAME} ${PORTVERSION}

.for _SCRIPT in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${_SCRIPT} ${STAGEDIR}${PREFIX}/sbin
.endfor
	
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/snmp
	${INSTALL_DATA} ${WRKSRC}/snmptt.ini ${STAGEDIR}${PREFIX}/etc/snmp/snmptt.ini-dist
	${INSTALL_DATA} ${WRKSRC}/examples/snmptt.conf.generic ${STAGEDIR}${PREFIX}/etc/snmp/snmptt.conf.generic-dist

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for _DOC in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/docs/${_DOC} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

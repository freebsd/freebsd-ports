# ports collection makefile for:	snmptt
# Date created:				21 May 2004
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		snmptt
PORTVERSION=		1.3
CATEGORIES=		net-mgmt
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=		${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=	nistor@snickers.org
COMMENT=	SNMP trap handler/translator/swiss-army-knife

RUN_DEPENDS=	net-snmp>=0:${PORTSDIR}/net-mgmt/net-snmp \
		p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

USE_PERL5=	yes

USE_RC_SUBR=	snmptt

SCRIPTS=	snmptt snmptt-net-snmp-test snmpttconvert \
		snmpttconvertmib snmptthandler
DOCS=		faqs.html index.html layout1.css snmptt.html \
		snmpttconvert.html snmpttconvertmib.html

.include <bsd.port.pre.mk>

do-build:

post-build:
	@${ECHO_CMD} ${WRKSRC}/snmptt ${WRKSRC}/snmptthandler ${WRKSRC}/snmptt.ini | ${XARGS} \
	 ${REINPLACE_CMD} -e \
	 "s|/etc/snmptt.ini|${PREFIX}/etc/snmptt.ini|g ; \
	  s|/etc/snmp/snmptt.ini|${PREFIX}/etc/snmp/snmptt.ini|g ; \
	  s|/etc/snmp/snmptt.conf|${PREFIX}/etc/snmp/snmptt.conf.generic|g"

do-install:
.for _SCRIPT in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${_SCRIPT} ${PREFIX}/sbin
.endfor
	${MKDIR} ${PREFIX}/etc/snmp
	${INSTALL_DATA} ${WRKSRC}/snmptt.ini ${PREFIX}/etc/snmp/snmptt.ini-dist
.if !exists(${PREFIX}/etc/snmp/snmptt.ini)
	${INSTALL_DATA} ${WRKSRC}/snmptt.ini ${PREFIX}/etc/snmp
.endif
	${INSTALL_DATA} ${WRKSRC}/examples/snmptt.conf.generic ${PREFIX}/etc/snmp/snmptt.conf.generic-dist
.if !exists(${PREFIX}/etc/snmp/snmptt.conf)
	${INSTALL_DATA} ${WRKSRC}/examples/snmptt.conf.generic ${PREFIX}/etc/snmp/snmptt.conf.generic
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for _DOC in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/docs/${_DOC} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

# ports collection makefile for:	snmptt
# Date created:				21 May 2004
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		snmptt
PORTVERSION=		0.9
CATEGORIES=		net-mgmt
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=	bms@FreeBSD.org
COMMENT=	SNMP trap handler/translator/swiss-army-knife

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

USE_PERL5=	yes
USE_REINPLACE=	yes

SCRIPTS=	snmptt snmptt-net-snmp-test snmpttconvert \
		snmpttconvertmib snmptthandler
DOCS=		faqs.html index.html layout1.css snmptt.html \
		snmpttconvert.html snmpttconvertmib.html

RUN_DEPENDS+=	\
	${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/net-snmp \
	${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%RC_DIR%%,${RC_DIR},g' \
		-e 's,%%RC_SUFX%%,${RC_SUFX},g'

PLIST_SUB+=	RC_DIR=${RC_DIR} \
		RC_SUFX=${RC_SUFX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500038
RC_SUBR?=	${DESTDIR}/etc/rc.subr
RC_DIR=		${DESTDIR}/etc/rc.d
RC_SUFX=
.else
USE_RC_SUBR=	yes
RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh
.endif

do-build:

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/snmptt.sh > ${WRKDIR}/snmptt.sh
	@${ECHO_CMD} ${WRKSRC}/snmptt ${WRKSRC}/snmptthandler | ${XARGS} \
	 ${REINPLACE_CMD} -e \
	 "s|/etc/snmptt.ini|${PREFIX}/etc/snmptt.ini|g ; \
	  s|/etc/snmp/snmptt.ini|${PREFIX}/etc/snmp/snmptt.ini|g"

do-install:
.for _SCRIPT in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${_SCRIPT} ${PREFIX}/sbin
.endfor
	${INSTALL_DATA} ${WRKSRC}/snmptt.ini ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/examples/snmptt.conf.generic ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for _DOC in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/docs/${_DOC} ${DOCSDIR}
.endfor
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/snmptt.sh ${RC_DIR}/snmptt${RC_SUFX}

.include <bsd.port.post.mk>

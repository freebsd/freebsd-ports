# New ports collection makefile for:	nagiostat
# Date created:			20 July 2004
# Whom:				Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nagiostat
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Nagiostat parses performance-data from Nagios and generates graphs

RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool \
		nagios:${PORTSDIR}/net-mgmt/nagios

USE_PERL5=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NAGIOSDIR?=	/var/spool/nagios
DOC_FILES=	README GPL.txt

NAGIOSWWWDIR?=	www/nagios
PLIST_SUB+=	NAGIOSWWWDIR=${NAGIOSWWWDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%NAGIOSTATCONFDIR%%|${PREFIX}/etc/|' \
		-e 's|%%NAGIOSTATDIR%%|${PREFIX}/libexec/${PORTNAME}/|' \
		-e 's|%%NAGIOSTATRRD%%|${NAGIOSDIR}/${PORTNAME}rrd/|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/nagiostat ${WRKSRC}/nagiostat.conf ${WRKSRC}/README
do-install:
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	@${MKDIR} ${NAGIOSDIR}/${PORTNAME}rrd
	@${INSTALL_SCRIPT} ${WRKSRC}/nagiostat ${PREFIX}/libexec/${PORTNAME}/
	@${LN} -fs ${PREFIX}/libexec/${PORTNAME}/nagiostat ${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/nagiostat.cgi
	@${INSTALL_DATA} ${WRKSRC}/nagiostat.conf ${PREFIX}/etc/nagiostat.conf-sample
	@${INSTALL_DATA} ${WRKSRC}/graph.gif ${PREFIX}/${NAGIOSWWWDIR}/images/logos
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}/html-templates/
	@${INSTALL_DATA} ${WRKSRC}/html-templates/default.html ${PREFIX}/libexec/${PORTNAME}/html-templates/
	@${INSTALL_DATA} ${WRKSRC}/html-templates/graphindex.html ${PREFIX}/libexec/${PORTNAME}/html-templates/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

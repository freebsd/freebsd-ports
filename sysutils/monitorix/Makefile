# New ports collection makefile for:	monitorix
# Date created:				15 Aug 2010
# Whom:					Olli Hauer <ohauer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	monitorix
PORTVERSION=	1.5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.monitorix.org/

MAINTAINER=	admin@mjbrune.org
COMMENT=	A web based monitoring system

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool
BUILD_DEPENDS=	${SITE_PERL}/LWP/Parallel.pm:${PORTSDIR}/www/p5-ParallelUA

LICENSE=	GPLv2

OPTIONS=	REPORTS "Mail HTML reports to a given address" off

.include <bsd.port.options.mk>

MAN5=		monitorix.conf.5
MANCOMPRESSED=	no
NO_BUILD=	yes

CGIDIR?=	${PREFIX}/www/cgi-bin
#REPORTS?=	true
# owner of $WWWROOT/imgs
WWW_OWNER?=	${WWWOWN}
WWW_GROUP?=	${WWWGRP}
DATADIR=	${INSTDIR}
REPORT_LANG=	ca de en it
INSTDIR=	${PREFIX}/${PORTNAME}
# WWWROOT: (WWWDIR - portname), we need the resulting path for a variable in monitorix.conf
WWWROOT=	${WWWDIR:S,${PORTNAME},,}

SUB_FILES=	pkg-message
SUB_LIST=	PERL=${PERL} INSTDIR=${INSTDIR}
PLIST_SUB+=	CGIDIR=${CGIDIR:S,${PREFIX}/,,} WWW_OWNER=${WWW_OWNER} WWW_GROUP=${WWW_GROUP}

WWW_FILES=	logo_top.png logo_bot.png monitorixico.png
DOCS=		COPYING Changes README README.FreeBSD README.nginx TODO \
		monitorix-alert.sh monitorix-apache.conf
REPORT_FILES=	imgs_email/blank.png imgs_email/logo.jpg imgs_email/signature.png \
		imgs_email/title.jpg traffic_report.html traffic_report.sh

.if defined(WITH_REPORTS)
RUN_DEPENDS+=	metamail>=2.7:${PORTSDIR}/mail/metamail
PLIST_SUB+=	REPORTS=""
.else
PLIST_SUB+=	REPORTS="@comment "
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DATADIR=${DATADIR}	Where do you put RRD databases?"
	@${ECHO_MSG} "CGIDIR=${CGIDIR}	Where do you put cgi?"
	@${ECHO_MSG} "WWWDIR=${WWWDIR}	Where do you put httpd's document root?"
	@${ECHO_MSG} ""

post-patch:
.for f in cgi conf pl
	@${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|" ${WRKSRC}/monitorix.${f}
.endfor
# Notes about the adjustments for default configuration:
# - set FreeBSD as OSTYPE
# - set a generic WWWROOT, since we can include it in the webserver config
# - milter-greylist use a new database path on FreeBSD
# - FreeBSD's interface name came from the NIC, the lo0 interface is almost everytime present
# - file/directory handling outside ${PREFIX} with ports is silly. We don't want to rewrite
#   monitorix.pl therefore we use ${PREFIX} instead /var/db/!
	@${REINPLACE_CMD} -e 's|our \$$OSTYPE = \"Linux-RHFC\"|our \$$OSTYPE = \"FreeBSD\"|' \
		-e "s|/usr/local/www/apache22/data|${WWWROOT}|" \
		-e "s|/var/lib/milter-greylist/db/greylist.db|/var/milter-greylist/greylist.db|" \
		-e "s|eth0|lo0|g" -e "s|/var/db/monitorix/|${INSTDIR}/|" \
		-e "s|%%INSTDIR%%|${INSTDIR}|g" ${WRKSRC}/monitorix.conf
.for d in ${REPORT_LANG}
	@${REINPLACE_CMD} -e "s|^rm|${RM}|g" -e "s|/bin/sed|${SED}|g" \
		-e "s|/usr/bin/metasend|${PREFIX}/bin/metasend|g" \
		-e "s|\"tmp|\"/tmp/${PORTNAME}_report|g" ${WRKSRC}/reports/${d}/traffic_report.sh
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/monitorix.pl ${PREFIX}/sbin/
	@${MKDIR} ${WWWDIR}/imgs
	@${CHOWN} ${WWW_OWNER}:${WWW_GROUP} ${WWWDIR}/imgs
	@for f in ${WWW_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${WWWDIR}/; \
	done
	@${MKDIR} ${CGIDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/monitorix.cgi ${CGIDIR}/
.for m in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/man/man5/$m ${PREFIX}/man/man5/
.endfor
.if defined(WITH_REPORTS)
. for l in ${REPORT_LANG}
	@${MKDIR} ${PREFIX}/${PORTNAME}/reports/${l}/imgs_email
.	for f in ${REPORT_FILES}
		@${INSTALL_DATA} ${WRKSRC}/reports/${l}/${f} ${PREFIX}/${PORTNAME}/reports/${l}/${f}
.	endfor
. endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for doc in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${doc} ${DOCSDIR}; \
	done
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/monitorix.conf ${PREFIX}/etc/monitorix.conf.sample
	@if [ ! -f ${PREFIX}/etc/monitorix.conf ]; then \
		${CP} -p ${PREFIX}/etc/monitorix.conf.sample ${PREFIX}/etc/monitorix.conf ; \
	fi
	@${MKDIR} ${DATADIR}/usage
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

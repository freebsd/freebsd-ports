# New ports collection makefile for:	monitorix
# Date created:				15 Aug 2010
# Whom:					Olli Hauer <ohauer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	monitorix
PORTVERSION=	2.1.2
PORTREVISION?=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.monitorix.org/ \
		http://www.monitorix.org/old_versions/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A web based monitoring system

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS=	${SITE_PERL}/LWP/Parallel.pm:${PORTSDIR}/www/p5-ParallelUA \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite

LICENSE=	GPLv2

OPTIONS=	REPORTS "Mail HTML reports to a given address" off

.include <bsd.port.options.mk>

USE_PERL=	5.8+
MAN5=		monitorix.conf.5
MANCOMPRESSED=	no
NO_BUILD=	yes
USE_RC_SUBR=	${PORTNAME}

CGIDIR?=	www/cgi-bin
CGIPATH?=	cgi-bin
WWW_OWNER?=	${WWWOWN}
WWW_GROUP?=	${WWWGRP}
REPORT_LANG=	ca de en it
WWWROOT=	${WWWDIR:S,/${PORTNAME}$,,}

SUB_FILES=	pkg-message
SUB_LIST=	PERL=${PERL}

PLIST_SUB+=	CGIDIR=${CGIDIR} \
		WWW_OWNER=${WWW_OWNER} \
		WWW_GROUP=${WWW_GROUP}

WWW_FILES=	logo_top.png \
		logo_bot.png \
		monitorixico.png

PORTDOCS=	COPYING \
		Changes \
		README \
		README.FreeBSD \
		monitorix-alert.sh \
		monitorix-apache.conf

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
	@${ECHO_MSG} "CGIPATH=${CGIPATH}	What is the relative URL for cgi files?"
	@${ECHO_MSG} "WWWDIR=${WWWDIR}	Where do you put httpd's document root?"
	@${ECHO_MSG} ""

post-patch:
# Set FreeBSD path for perl in shebang and absolute sysctl so as not to break
# in cgi-bin
.for f in monitorix.cgi monitorix.conf monitorix reports/send_reports
	@${REINPLACE_CMD} -e "1s|^\(#!\).*|\1${PERL}|" \
		-e 's|"\([^/]sysctl\)|"/sbin/\1|' \
		${WRKSRC}/${f}
.endfor
# eth0 doesn't exist in FreeBSD! Also let's set our own paths.
# No iptables, so we'll disable PORT_GRAPH
	@${REINPLACE_CMD} \
		-e 's|\($$BASE_DIR = "\)[^"]*|\1${WWWDIR}/|' \
		-e 's|\($$BASE_LIB = "\)[^"]*|\1${DATADIR}/|' \
		-e 's|\($$BASE_CGI = "\)[^"]*|\1${CGIPATH}/|' \
		-e 's|\($$SECURE_LOG= "\)[^"]*|\1/var/log/auth.log|' \
		-e "s|/var/lib/milter-greylist/db/|/var/milter-greylist/|" \
		-e "s|eth0|lo0|g" \
		-e 's|\("port"[^Y]*\)Y|\1N|' \
			${WRKSRC}/monitorix.conf

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/monitorix ${PREFIX}/sbin/
	@${MKDIR} ${WWWDIR}/imgs
	@${CHOWN} ${WWW_OWNER}:${WWW_GROUP} ${WWWDIR}/imgs
	@for f in ${WWW_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${WWWDIR}/; \
	done
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/monitorix.cgi ${PREFIX}/${CGIDIR}/
.for m in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/man/man5/$m ${MAN5PREFIX}/man/man5/
.endfor
.if defined(WITH_REPORTS)
	@${MKDIR} ${WWWDIR}/reports
. for l in ${REPORT_LANG}
	@${INSTALL_DATA} ${WRKSRC}/reports/${l}.html \
		${WWWDIR}/reports/
. endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for doc in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${doc} ${DOCSDIR}; \
	done
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/monitorix.conf ${PREFIX}/etc/monitorix.conf.sample
	@if [ ! -f ${PREFIX}/etc/monitorix.conf ]; then \
		${CP} -p ${PREFIX}/etc/monitorix.conf.sample \
			${PREFIX}/etc/monitorix.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

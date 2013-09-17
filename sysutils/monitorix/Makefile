# Created by: Olli Hauer <ohauer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	monitorix
PORTVERSION=	3.3.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.monitorix.org/ \
		http://www.monitorix.org/old_versions/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A web based monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS=	p5-ParallelUA>=0:${PORTSDIR}/www/p5-ParallelUA \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General

USES=		perl5
USE_PERL5=	run
MAN5=		monitorix.conf.5
MAN8=		monitorix.8
MANCOMPRESSED=	no
NO_BUILD=	yes
USE_RC_SUBR=	${PORTNAME}

DBDIR?=		/var/db/${PORTNAME}
CGIDIR?=	www/cgi-bin
CGIPATH?=	/cgi-bin
WWW_OWNER?=	${WWWOWN}
WWW_GROUP?=	${WWWGRP}
REPORT_LANG=	ca de en it pl
WWWROOT=	${WWWDIR:S,/${PORTNAME}$,,}

SUB_FILES=	pkg-message
SUB_LIST=	PERL=${PERL} \
		DBDIR=${DBDIR}

PLIST_SUB+=	CGIDIR=${CGIDIR} \
		WWW_OWNER=${WWW_OWNER} \
		WWW_GROUP=${WWW_GROUP} \
		DBDIR=${DBDIR}

WWW_FILES=	logo_top.png \
		logo_bot.png \
		monitorixico.png

PORTDOCS=	*
PORTDATA=	*.pm

.include <bsd.port.options.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DBDIR=${DBDIR}	Where do you put RRD databases?"
	@${ECHO_MSG} "CGIDIR=${CGIDIR}	Where do you put cgi?"
	@${ECHO_MSG} "CGIPATH=${CGIPATH}	What is the relative URL for cgi files?"
	@${ECHO_MSG} "WWWDIR=${WWWDIR}	Where do you put httpd's document root?"
	@${ECHO_MSG} ""

post-patch:
# Let's set our own paths.
# No iptables, so we'll disable PORT_GRAPH
	@${REINPLACE_CMD} '\,^use lib,s,/usr/lib/monitorix,${DATADIR},' \
		${WRKSRC}/${PORTNAME} \
		${WRKSRC}/${PORTNAME}.cgi
	@${REINPLACE_CMD} \
		-e 's|^\(base_dir *= *\).*|\1${WWWDIR}/|' \
		-e 's|^\(base_lib *= *\).*|\1${DBDIR}/|' \
		-e 's|^\(base_cgi *= *\).*|\1${CGIPATH}/|' \
		-e 's|^\(secure_log[[:space:]]*= *\).*|\1/var/log/auth.log|' \
		-e "s|/var/lib/milter-greylist/db/|/var/milter-greylist/|" \
		-e 's|^\([[:space:]]*port[^=]*=[^y]*\)y|\1n|' \
			${WRKSRC}/monitorix.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/monitorix ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DATADIR}/
	@${MKDIR} ${WWWDIR}
	@${INSTALL} -d -o ${WWW_OWNER} -g ${WWW_GROUP} ${WWWDIR}/imgs
.for f in ${WWW_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${WWWDIR}/
.endfor
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@${LN} -s ${PREFIX}/${CGIDIR} ${WWWDIR}/cgi
	@${INSTALL_SCRIPT} ${WRKSRC}/monitorix.cgi ${PREFIX}/${CGIDIR}/
.for c in 5 8
. for m in ${MAN$c}
	@${INSTALL_MAN} ${WRKSRC}/man/man$c/$m ${MAN$cPREFIX}/man/man$c/
. endfor
.endfor
	@${MKDIR} ${WWWDIR}/reports
.for l in ${REPORT_LANG}
	@${INSTALL_DATA} ${WRKSRC}/reports/${l}.html \
		${WWWDIR}/reports/$l.html.sample
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
. for f in docs/* README README.FreeBSD README.nginx Changes
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
. endfor
.endif

post-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${WWWDIR}/usage
	@${INSTALL_DATA} ${WRKSRC}/monitorix.conf \
		${PREFIX}/etc/monitorix.conf.sample
	@if [ ! -f ${PREFIX}/etc/monitorix.conf ]; then \
		${CP} -p ${PREFIX}/etc/monitorix.conf.sample \
			${PREFIX}/etc/monitorix.conf ; \
	fi
	if [ ! -d ${DBDIR} ]; then \
		${INSTALL} -d -o ${WWW_OWNER} -g ${WWW_GROUP} ${DBDIR}; \
		if [ -f ${DATADIR}/fs.rrd ]; then \
			${MV} ${DATADIR}/*.rrd ${DBDIR}; \
		fi; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

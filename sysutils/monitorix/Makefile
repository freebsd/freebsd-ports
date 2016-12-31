# $FreeBSD$

PORTNAME=	monitorix
PORTVERSION=	3.5.1
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.monitorix.org/ \
		http://www.monitorix.org/old_versions/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Web based monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	librrd.so:databases/rrdtool
RUN_DEPENDS=	p5-ParallelUserAgent>=0:www/p5-ParallelUserAgent \
		p5-CGI>=0:www/p5-CGI \
		p5-libwww>=0:www/p5-libwww \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-DBI>=0:databases/p5-DBI \
		p5-HTTP-Server-Simple>=0:www/p5-HTTP-Server-Simple \
		p5-Config-General>=0:devel/p5-Config-General

USES=		perl5
USE_PERL5=	run
NO_ARCH=	yes
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
		-e '\|user *= *nobody|s|nobody|www|' \
		-e '\|group *= *nobody|s|nobody|www|' \
		-e 's|^\(base_dir *= *\).*|\1${WWWDIR}/|' \
		-e 's|^\(base_lib *= *\).*|\1${DBDIR}/|' \
		-e 's|^\(base_cgi *= *\).*|\1${CGIPATH}/|' \
		-e 's|^\(secure_log[[:space:]]*= *\).*|\1/var/log/auth.log|' \
		-e "s|/var/lib/milter-greylist/db/|/var/milter-greylist/|" \
		-e 's|^\([[:space:]]*port[^=]*=[^y]*\)y|\1n|' \
			${WRKSRC}/monitorix.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/monitorix ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${STAGEDIR}${WWWDIR} && ${MKDIR} usage imgs)
	${INSTALL_DATA} ${WWW_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${WWWDIR}/
	${MKDIR} ${STAGEDIR}${PREFIX}/${CGIDIR}
	${LN} -sf ${PREFIX}/${CGIDIR} ${STAGEDIR}${WWWDIR}/cgi
	${INSTALL_SCRIPT} ${WRKSRC}/monitorix.cgi \
		${STAGEDIR}${PREFIX}/${CGIDIR}/
.for s in 5 8
	${INSTALL_MAN} ${WRKSRC}/man/man$s/* ${STAGEDIR}${PREFIX}/man/man$s/
.endfor
	${MKDIR} ${STAGEDIR}${WWWDIR}/reports
.for l in ${REPORT_LANG}
	${INSTALL_DATA} ${WRKSRC}/reports/${l}.html \
		${STAGEDIR}${WWWDIR}/reports/$l.html.sample
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in docs/*[^t] README README.FreeBSD README.nginx Changes
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/monitorix.conf \
		${STAGEDIR}${PREFIX}/etc/monitorix.conf.sample
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>

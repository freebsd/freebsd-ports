# Created by: rea-fbsd@codelabs.ru
# $FreeBSD$

PORTNAME=	pnp
PORTVERSION=	0.6.26
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/pnp4nagios/PNP-0.6
DISTNAME=	pnp4nagios-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER?=	lme@FreeBSD.org
COMMENT?=	Nagios / Icinga performance data collector and grapher

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/rrdtool:databases/rrdtool
RUN_DEPENDS?=	${LOCALBASE}/bin/rrdtool:databases/rrdtool \
		nagios:net-mgmt/nagios

MAKE_JOBS_UNSAFE=	yes
USES=		dos2unix perl5 php php:web

OPTIONS_DEFINE=	PDF
OPTIONS_DEFAULT=	PDF
PDF_DESC=	Use built-in fpdf library to produce PDF views

.include <bsd.port.options.mk>

USE_PHP=	gd iconv json pcre session simplexml sockets xml zlib

USE_RC_SUBR=	npcd

DOS2UNIX_REGEX=	'.*\.\(php\|js\|txt\)$$'

NAGIOSDIR?=	/var/spool/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
PNP_STATE=	${NAGIOSDIR}/pnp
PNP_RRDS=	${PNP_STATE}/rrd
PNP_SPOOL=	${PNP_STATE}/perfspool
PNP_URL?=	${NAGIOSHTMURL}/pnp
FPDF_DIR?=	share/fpdf

PDF_EXTRA_PATCHES_OFF+=	${FILESDIR}/extra-patch-disable-pdf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	\
	--sysconfdir=${ETCDIR} \
	--datarootdir=${WWWDIR} \
	--datadir=${WWWDIR} \
	--localstatedir=/var/log \
	--with-rrdtool=${LOCALBASE}/bin/rrdtool \
	--with-perfdata-dir=${PNP_RRDS} \
	--with-perfdata-spool-dir=${PNP_SPOOL} \
	--with-nagios-user=${NAGIOSUSER} \
	--with-nagios-group=${NAGIOSGROUP}
# Get rid of INSTALL_OPTS that are set by configure --
# we want the things to be installed with root:wheel and
# NAGIOSUSER:NAGIOSGROUP are going to the configuration files.
MAKE_ARGS=	INSTALL_OPTS=
INSTALL_TARGET=	install install-config

PLIST_SUB+=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

SUB_FILES=	pkg-message
SUB_LIST=	PNP_RRDS=${PNP_RRDS} \
		PNP_URL=${PNP_URL} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP}

SAMPLE_CONFIGS=	lighttpd.pnp4nagios.conf nginx.pnp4nagios.conf httpd.conf

.if ${PORT_OPTIONS:MPDF}
PNP_USE_FPDF=	1
.else
PNP_USE_FPDF=	0
.endif

post-patch:
	@${REINPLACE_CMD} \
  -e's|^\$$conf\['\''use_fpdf'\''\] = [[:digit:]];|$$conf['\''use_fpdf'\''] = ${PNP_USE_FPDF};|' \
  -e's|^\$$conf\['\''nagios_base'\''\] = "/nagios/cgi-bin";|$$conf\['\''nagios_base'\''\] = "${NAGIOSHTMURL}/cgi-bin";|' \
  -e's|/usr/local/check_mk/|/usr/local/share/check_mk/|g' \
  -e's|/usr/local/nagios/var/rw/live|/${NAGIOSDIR}/rw/live|' \
  "${WRKSRC}/sample-config/pnp/config.php.in"
.for f in ${SAMPLE_CONFIGS}
	@${REINPLACE_CMD} -e 's|@BASE_URL@|${PNP_URL}|g' -e 's|@datarootdir@|${WWWDIR}|g' \
  -e 's|/usr/local/nagios/etc|${PREFIX}/etc/${NAGIOSUSER}|' -e 's|Nagios|${NAGIOSUSER}|' \
  "${WRKSRC}/sample-config/${f}.in"
.endfor
	@${LN} -fs ../en_US/dwnld.html ${WRKSRC}/share/pnp/documents/de_DE/dwnld.html

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${SAMPLE_CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/sample-config/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/npcd.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>

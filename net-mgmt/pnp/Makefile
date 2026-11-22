PORTNAME=	pnp
PORTVERSION=	0.6.27.5
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Nagios / Icinga performance data collector and grapher
WWW=		https://github.com/pnp4nagios/pnp4nagios

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/rrdtool:databases/rrdtool
RUN_DEPENDS?=	${LOCALBASE}/bin/rrdtool:databases/rrdtool

FLAVORS?=	default nagios4
FLAVOR?=	${FLAVORS:[1]}

nagios4_PKGNAMESUFFIX=	-nagios4

USES=		dos2unix perl5 php:web tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	pnp4nagios
GH_PROJECT=	pnp4nagios
GH_TAGNAME=	8c97c7d

MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL?=	${FLAVORS:N${FLAVOR}:S/^/pnp-/} pnp-icinga2

OPTIONS_DEFINE=		EXAMPLES PDF
OPTIONS_DEFAULT=	PDF
PDF_DESC=		Use built-in fpdf library to produce PDF views

PDF_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-disable-pdf

.include <bsd.port.options.mk>

.if ${FLAVOR} == nagios4
RUN_DEPENDS+=	nagios:net-mgmt/nagios4
.elif ${FLAVOR} == default
RUN_DEPENDS+=	nagios:net-mgmt/nagios
.endif

USE_PHP=	gd iconv session simplexml sockets xml zlib

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

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${WWWDIR} \
			--datarootdir=${WWWDIR} \
			--localstatedir=/var/log \
			--sysconfdir=${ETCDIR} \
			--with-http_group=${WWWGRP} \
			--with-http_server_base=${WWWDIR} \
			--with-http_user=${WWWOWN} \
			--with-nagios-cfg=${LOCALBASE}/etc/nagios \
			--with-nagios-group=${NAGIOSGROUP} \
			--with-nagios-user=${NAGIOSUSER} \
			--with-perfdata-dir=${PNP_RRDS} \
			--with-perfdata-spool-dir=${PNP_SPOOL} \
			--with-piddir=/var/run \
			--with-rrdtool=${LOCALBASE}/bin/rrdtool

# Get rid of INSTALL_OPTS that are set by configure --
# we want the things to be installed with root:wheel and
# NAGIOSUSER:NAGIOSGROUP are going to the configuration files.
MAKE_ARGS?=	INSTALL_OPTS=
INSTALL_TARGET=	install

PLIST_SUB+=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NAGIOSUSER=${NAGIOSUSER} \
		WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

SUB_FILES=	pkg-message
SUB_LIST=	NAGIOSGROUP=${NAGIOSGROUP} \
		NAGIOSUSER=${NAGIOSUSER} \
		PNP_RRDS=${PNP_RRDS} \
		PNP_URL=${PNP_URL}

SAMPLE_CONFIGS=	apache.pnp4nagios.conf lighttpd.pnp4nagios.conf \
		nginx.pnp4nagios.conf

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
  "${WRKSRC}/sample-config/config_samples/config.php.in"
.for f in ${SAMPLE_CONFIGS}
	@${REINPLACE_CMD} -e 's|@BASE_URL@|${PNP_URL}|g' -e 's|@datarootdir@|${WWWDIR}|g' \
  -e 's|/usr/local/nagios/etc|${PREFIX}/etc/${NAGIOSUSER}|' -e 's|Nagios|${NAGIOSUSER}|' \
  "${WRKSRC}/sample-config/config_samples/${f}.in"
.endfor
	@${LN} -fs ../en_US/dwnld.html ${WRKSRC}/share/pnp/documents/de_DE/dwnld.html

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${SAMPLE_CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/sample-config/config_samples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>

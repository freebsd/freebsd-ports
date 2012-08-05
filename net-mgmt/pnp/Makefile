# New ports collection makefile for:	pnp
# Date created:				16 August 2008
# Whom:					rea-fbsd@codelabs.ru
#
# $FreeBSD$
#

PORTNAME=	pnp
PORTVERSION=	0.6.10
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=pnp4nagios/PNP-0.6
DISTNAME=	pnp4nagios-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Nagios performance data collector and grapher

BUILD_DEPENDS=	${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS=	${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool \
		nagios:${PORTSDIR}/net-mgmt/nagios

MAKE_JOBS_UNSAFE=	yes

OPTIONS=	PDF "Use built-in fpdf library to produce PDF views" ON

.include <bsd.port.options.mk>

LICENSE=	GPLv2
PATCH_STRIP=	-p1
USE_PERL5=	yes
USE_PHP=	gd iconv json pcre simplexml sockets xml zlib

WANT_PHP_WEB=	yes
USE_RC_SUBR=	npcd
MAN8=		npcd.8
USE_DOS2UNIX=	yes
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
SPOOL_DIRS=	${PNP_STATE}:${NAGIOSUSER}:${NAGIOSGROUP}:0750%${PNP_RRDS}:${NAGIOSUSER}:${NAGIOSGROUP}:0750%${PNP_SPOOL}:${NAGIOSUSER}:${NAGIOSGROUP}:0750

.if !defined(WITH_PDF)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-disable-pdf
.endif

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

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message
SUB_LIST=	SPOOL_DIRS=${SPOOL_DIRS} \
		PNP_RRDS=${PNP_RRDS} \
		PNP_URL=${PNP_URL} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP}

.if defined(WITH_PDF)
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

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.for m in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${m} ${MAN8PREFIX}/man/man8/${m}
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

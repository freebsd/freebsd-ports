# New ports collection makefile for:	pnp
# Date created:				16 August 2008
# Whom:					rea-fbsd@codelabs.ru
#
# $FreeBSD$
#

PORTNAME=	pnp
PORTVERSION=	0.4.14
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}4nagios/PNP/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	Nagios performance data collector and grapher

BUILD_DEPENDS=	${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS=	${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool \
		nagios:${PORTSDIR}/net-mgmt/nagios

OPTIONS=	PDF "Use built-in fpdf library to produce PDF views" ON

USE_PHP=	zlib gd xml pcre
WANT_PHP_WEB=	yes
USE_RC_SUBR=	npcd.sh
MAN1=		pnpsender.1

NAGIOSDIR?=	/var/spool/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
PNP_STATE=	${NAGIOSDIR}/pnp
PNP_RRDS=	${PNP_STATE}/rrd
PNP_SPOOL=	${PNP_STATE}/perfspool
FPDF_DIR?=	share/fpdf

.if defined(WITH_PDF)
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-share::pnp::include::function.inc.php
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	\
	--sysconfdir=${PREFIX}/etc/pnp \
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
SUB_LIST=	PNP_STATE=${PNP_STATE} \
		PNP_RRDS=${PNP_RRDS} \
		PNP_SPOOL=${PNP_SPOOL} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP}

# All files in share/pnp/include/ are installed, so if we patched something
# in that directory, we must clean the '.orig' files -- they shouldn't be
# installed.
PNP_CLEAN_PATCHED=	share/pnp/include/function.inc.php.orig

.if defined(WITH_PDF)
PNP_USE_FPDF=	1
.else
PNP_USE_FPDF=	0
.endif
post-patch:
	@${REINPLACE_CMD} \
  -e's|^\$$conf\['\''use_fpdf'\''\] = [[:digit:]];|$$conf['\''use_fpdf'\''] = ${PNP_USE_FPDF};|' \
  -e's|^\$$conf\['\''nagios_base'\''\] = "/nagios/cgi-bin";|$$conf\['\''nagios_base'\''\] = "${NAGIOSHTMURL}/cgi-bin";|' \
  "${WRKSRC}/sample-config/pnp/config.php.in"
.for pch in ${PNP_CLEAN_PATCHED}
	@${RM} -f "${WRKSRC}/${pch}"
.endfor

post-install:
.for m in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${m} ${MAN1PREFIX}/man/man1/${m}
.endfor
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

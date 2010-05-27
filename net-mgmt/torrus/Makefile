# New ports collection makefile for:	torrus
# Date created:				July 13th, 2005
# Whom:	      				Corey Smith <corsmith@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	torrus
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	corsmith@gmail.com
COMMENT=	The Data Series Processing Framework - think mrtg with xml configs

BUILD_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/databases/rrdtool \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon \
		${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session
LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		db-4.3.0:${PORTSDIR}/databases/db43

.if defined(WITH_MODPERL2)
USE_APACHE= 2.0+
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/APR/Request.pm:${PORTSDIR}/www/p5-libapreq2
.else
USE_APACHE= 1.3
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif

USE_PERL5_RUN=	5.8.1+
GNU_CONFIGURE=	YES

TORRUS_USER?=	torrus
TORRUS_RRDDIR?=	var/torrus/collector_rrd

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		var_user=${TORRUS_USER} var_group=${TORRUS_USER} \
		varprefix=${PREFIX}/var/torrus torrus_user=${TORRUS_USER} \
		defrrddir=${PREFIX}/${TORRUS_RRDDIR} \
		pkghome=${PREFIX}/share/torrus \
		pkgbindir=${PREFIX}/libexec/torrus \
		pkgdocdir=${PREFIX}/share/doc/torrus \
		exmpdir=${PREFIX}/share/examples/torrus \
		perllibdir=${SITE_PERL} \
		scriptsdir=${PREFIX}/libexec/torrus/scripts \
		--enable-pkgonly

MAN1=		torrus.1 torrus_acledit.1 torrus_buildsearchdb.1 \
		torrus_cleanup.1 torrus_clearcache.1 torrus_collector.1 \
		torrus_compilexml.1 torrus_configinfo.1 \
		torrus_configsnapshot.1 torrus_devdiscover.1 torrus_genddx.1 \
		torrus_genlist.1 torrus_genreport.1 torrus_monitor.1 \
		torrus_rrddir2xml.1 torrus_schedulerinfo.1 torrus_srvderive.1 \
		torrus_ttproclist.1

MAN7=		torrus_action_printemail.7 torrus_action_snmptrap.7 \
		torrus_action_notify.7 torrus_install_plugin.7

.include <bsd.port.pre.mk>

pre-fetch:
	@${ECHO_CMD} PREFIX = ${PREFIX}
	@${ECHO_CMD}
	@${ECHO_CMD} "This port supports either mod_perl 1 or mod_perl 2"
	@${ECHO_CMD}
	@${ECHO_CMD} "  mod_perl 1.x support (DEFAULT)"
	@${ECHO_CMD} "  WITH_MODPERL2=yes  Enables mod_perl 2.x support"
	@${ECHO_CMD}
.if !defined(WITH_MODPERL2)
	@${ECHO_CMD} "Enabling mod_perl 1.x support."
.else
	@${ECHO_CMD} "Enabling mod_perl 2.x support."
.endif
	@${ECHO_CMD}

pre-install:
	@if ! pw groupshow ${TORRUS_USER}; then \
		pw groupadd ${TORRUS_USER}; \
	fi
	@if ! pw usershow ${TORRUS_USER}; then \
		pw useradd ${TORRUS_USER} -g ${TORRUS_USER} \
			-h - -d ${PREFIX}/torrus -c "torrus daemon"; \
		pw usermod www -G ${TORRUS_USER}; \
	fi

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/init.d/torrus ${PREFIX}/etc/rc.d/torrus.sh
	@${MKDIR} -m 2775 -p ${PREFIX}/${TORRUS_RRDDIR}
	@${CHOWN} ${TORRUS_USER}:${TORRUS_USER} ${PREFIX}/${TORRUS_RRDDIR}
	@${CAT} pkg-message

.include <bsd.port.post.mk>
